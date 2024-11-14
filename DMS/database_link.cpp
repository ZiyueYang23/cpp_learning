#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>

SQLHENV hEnv;
SQLHDBC hDbc;
SQLHSTMT hStmt;

void initConnection()
{
    SQLRETURN ret;

    // 初始化环境句柄
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cout << "Error allocating environment handle!" << std::endl;
        return;
    }

    ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cout << "Error setting environment attribute!" << std::endl;
        return;
    }

    // 分配连接句柄
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cout << "Error allocating connection handle!" << std::endl;
        return;
    }

    // 建立数据库连接
    ret = SQLDriverConnect(hDbc, NULL, (SQLCHAR *)"DSN=yzy_sql_server;UID=sa;PWD=Yzy20050723;",
                           SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
    if (SQL_SUCCEEDED(ret))
    {
        std::cout << "Connected to the database successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to connect to the database!" << std::endl;
    }
}

void closeConnection()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}
