//
//  NetHelper.hpp
//  net
//
//  Created by ashan on 2021/6/1.
//

#ifndef NetHelper_hpp
#define NetHelper_hpp

#include <iostream>

namespace syncframe {
class NetHelper {
 public:
  int static RequestGet(const std::string& host,
                        const std::string& port,
                        const std::string& page,
                        const std::string& data,
                        std::string& reponse_data);
  int static RequestPost(const std::string& host,
                         const std::string& port,
                         const std::string& page,
                         const std::string& data,
                         std::string& reponse_data);
};
}  // namespace syncframe

#endif /* NetHelper_hpp */
