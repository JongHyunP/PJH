#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
	// 트랜지션 개념 중요함. 면접

	MYSQL conn;
	MYSQL_RES* pSqlRes;
	MYSQL_ROW sqlRow;

	cout << mysql_get_client_info() << endl;

	if (mysql_init(&conn) == nullptr)
	{
		cout << "mysql_init" << endl;
		return 1;
	}


	if (mysql_real_connect(&conn, "localhost", "whdgus1590", "zxcv5665!!", "test_game", 3306, NULL, 0) == nullptr)
	{
		cout << "mysql_real_connect fail!!" << endl;
		return 1;
	}

	if (mysql_select_db(&conn, "test_game"))
	{
		cout << "mysql_select_db fail!! : "<< mysql_errno(&conn) << " : " << mysql_error(&conn) <<endl; //에러 넘버와 에러 내용
		return 1;
	}

	//한글
	mysql_query(&conn, "set session character_set_connection = euckr");
	mysql_query(&conn, "set session character_set_results = euckr");
	mysql_query(&conn, "set session character_set_client = euckr");

	const  char* query = "SELECT * FROM user_data";

	int state = mysql_query(&conn, query);
	if (state == 0)
	{
		pSqlRes = mysql_store_result(&conn);
		if (pSqlRes != nullptr)//SELECT 문을 뺀 나머지는 null
		{
			int numCol = mysql_num_fields(pSqlRes);
			while ((sqlRow = mysql_fetch_row(pSqlRes)) != nullptr)
			{
				for (int i = 0; i < numCol; i++)
					cout << sqlRow[i] << " ";

				cout << endl;
			}
		}
		else
		{
			int errNo = mysql_errno(&conn);
			if (errNo != 0)
			{
				cout << "Error : " << mysql_error(&conn) << endl;
			}
		}

		mysql_free_result(pSqlRes);
	}

	mysql_close(&conn);

	return 0;
}