===============根据服务的wsdl生成web服务的解释.h文件=========
wsdl2h -s -o A.h A.wsdl http://192.xx.xx.xx/xx/A.wsdl
    # -s dont generate STL code(no std::string and no std::vector), 不指定这个需要stdlvector.h 头文件
    # -o 指定生成的头文件名称
    # -n 名字空间前缀，代替默认的ns
    # -c 产生纯C代码，否则是C++
    # -t 文件名，指定type map文件，默认为typemap.dat,该文件指定SOAP/XML和C/C++之间的转换规则
    # -e 禁止为enum成员加上命名空间前缀


=======================.h生成客户端代码========================
#mkdir client-soap;cd client-soap, 创建个目录，存放client端代码
soacpp2 -i -C -x A.h 
    # soapcpp2是构建SOAP C++源码的预编译器
    # -i 直接使用C++包装类 
    # -x不要生成xml示例文件 
    # -C 只生成客户端相关的代码。
    # -S 生成仅生成服务端代码.
    # -c 生成纯c代码，否则是C++代码
    # -I 指定import路径

========================生成服务端代码========================
soacpp2 -i -S -x A.h 
    # soapcpp2是构建SOAP C++源码的预编译器
    # -i 直接使用C++包装类 
    # -x不要生成一堆xml 
    # -S 只生成客户端相关的代码。

=======================编译===========
server:
    make ARCH=arm TYPE=server
    make ARCH=pc  TYPE=server
client:
    make ARCH=arm TYPE=client
    make ARCH=pc  TYPE=client

