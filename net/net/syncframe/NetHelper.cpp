//
//  NetHelper.cpp
//  net
//
//  Created by ashan on 2021/6/1.
//

#include "NetHelper.hpp"
#include "asio.hpp"

using namespace syncframe;
using asio::ip::tcp;
using std::string;

int NetHelper::RequestGet(const std::string& host,
                          const std::string& port,
                          const std::string& page,
                          const std::string& data,
                          std::string& reponse_data) {
  try {
    asio::io_service io_service;
    if (io_service.stopped())
      io_service.reset();

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(host, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    asio::connect(socket, endpoint_iterator);

    asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream << "POST " << page << "?" << data << " HTTP/1.0\r\n";
    request_stream << "Host: " << host << ":" << port << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";

    asio::write(socket, request);

    asio::streambuf response;
    asio::read_until(socket, response, "\r\n");

    // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);
    if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
      reponse_data = "Invalid response";
      return -2;
    }
    // 如果服务器返回非200都认为有错,不支持301/302等跳转
    if (status_code != 200) {
      reponse_data = "Response returned with status code != 200 ";
      return status_code;
    }

    // 传说中的包头可以读下来了
    std::string header;
    std::vector<string> headers;
    while (std::getline(response_stream, header) && header != "\r")
      headers.push_back(header);

    // 读取所有剩下的数据作为包体
    asio::error_code error;
    while (asio::read(socket, response, asio::transfer_at_least(1), error)) {
    }

    //响应有数据
    if (response.size()) {
      std::istream response_stream(&response);
      std::istreambuf_iterator<char> eos;
      reponse_data =
          string(std::istreambuf_iterator<char>(response_stream), eos);
    }

    if (error != asio::error::eof) {
      reponse_data = error.message();
      return -3;
    }
  } catch (std::exception& e) {
    reponse_data = e.what();
    return -4;
  }
  return 0;
}

int NetHelper::RequestPost(const std::string& host,
                           const std::string& port,
                           const std::string& page,
                           const std::string& data,
                           std::string& reponse_data) {
  try {
    asio::io_service io_service;
    if (io_service.stopped())
      io_service.reset();

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(host, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    asio::connect(socket, endpoint_iterator);

    asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream << "POST " << page << " HTTP/1.0\r\n";
    request_stream << "Connection: close\r\n\r\n";
    request_stream << data;

    asio::write(socket, request);
    asio::streambuf response;
    asio::read_until(socket, response, "\r\n");

    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);
    if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
      reponse_data = "Invalid response";
      return -2;
    }
    // 如果服务器返回非200都认为有错,不支持301/302等跳转
    if (status_code != 200) {
      reponse_data = "Response returned with status code != 200 ";
      return status_code;
    }

    // 传说中的包头可以读下来了
    std::string header;
    std::vector<string> headers;
    while (std::getline(response_stream, header) && header != "\r")
      headers.push_back(header);

    // 读取所有剩下的数据作为包体
    asio::error_code error;
    while (asio::read(socket, response, asio::transfer_at_least(1), error)) {
    }

    //响应有数据
    if (response.size()) {
      std::istream response_stream(&response);
      std::istreambuf_iterator<char> eos;
      reponse_data =
          string(std::istreambuf_iterator<char>(response_stream), eos);
    }

    if (error != asio::error::eof) {
      reponse_data = error.message();
      return -3;
    }
  } catch (std::exception& e) {
    reponse_data = e.what();
    return -4;
  }
  return 0;
}
