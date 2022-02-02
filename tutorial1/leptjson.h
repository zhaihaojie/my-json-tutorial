// 头文件声明 include guard 避免头文件多次引用
#ifndef LEPTJSON_H__
#define LEPTJSON_H__
// 设定数据类型 枚举类型
// 类似于struct structname|enum enumname 也是一个整体
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct{
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

int lept_parse(lept_value* v,const char* json);
lept_type lept_get_type(const lept_value* v);

#endif