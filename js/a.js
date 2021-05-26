log.log("gg");
log.info(123)
log.debug(version);
log.info("v8的版本",v8version);
log.error("this is error infomation");
log.warn("----------- 以下是读取的代码文件 -----------");
log.succ(io.readFile("/Users/ashan/workspace/v8-sample/js/a.js"));
io.writeFile("/Users/ashan/workspace/v8-sample/js/b.js", "test中文");
log.debug(version);
log.debug(version);