#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leptjson.h"
// http://c.biancheng.net/view/301.html 静态全局变量 只在本文件里有效
// static修饰符表明该变量在调用后要保持其值 下一次继续从这个值调用
// 因为是测试模块 所以在本文件中需要这样的静态全局变量
static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;
// 带参数宏定义
#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
// 静态函数只能在声明它的文件中可见，其他文件不能引用该函数
static void test_parse_null() {
    lept_value v;
    v.type = LEPT_TRUE;
    EXPECT_EQ_INT(LEPT_PARSE_OK, lept_parse(&v, "null"));
    EXPECT_EQ_INT(LEPT_NULL, lept_get_type(&v));
}

/* ... */

static void test_parse() {
    test_parse_null();
    /* ... */
}

int main(){
    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}