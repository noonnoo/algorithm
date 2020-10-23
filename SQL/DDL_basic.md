## SQL 기본 문법 - DDL (CREATE, ALTER, DROP, TRUNCATE)

#### 데이터 정의어(DDL)

데이터를 정의하는 언어, 생성, 변경, 삭제, 이름을 바꾸는 명령어


#### CREATE: 데이터 베이스 오브젝트 생성 
* db를 생성하고, student라는 테이블 생성 (컬럼: 학번, 이름, 전화번호)
```sql
CREATE DATABASE db; #db 생성
CREATE TABLE student  #student라는 테이블에 id, name, phone이라는 컬럼 생성
(
    id int NOT NULL  primary key auto_increment,
    name VARCHAR(10) NOT NULL,
    phone VARCHAR(20) NOT NULL
);
DESCRIBE student;
```  
* 결과
```
Field	Type	    Null	Key	  Default	Extra
id	     int	      NO	PRI	  NULL	  auto_increment
name	varchar(10)	  NO		  NULL	
phone	varchar(20)	  NO		  NULL	
```  

#### ALTER: 데이터 베이스 오브젝트 변경
* student에 학년을 저장하는 grade라는 컬럼 추가
```sql
ALTER TABLE student ADD grade VARCHAR(15) NOT NULL after name;  #열 추가
```
결과
```
Field	    Type	       Null 	Key 	Default	 Extra
id	         int	        NO  	PRI	    NULL	auto_increment
name	     varchar(10)	NO		        NULL	
grade	     varchar(15)	NO		        NULL	
phone	     varchar(20)	NO		        NULL	
student에 있는 name column의 데이터 타입 변경
```

```sql
ALTER TABLE student MODIFY name VARCHAR(15) NOT NULL;   #열 타입 변경
```
결과
```
Field	Type	        Null	Key	     Default	Extra
id	     int	          NO	PRI	      NULL	auto_increment
name	varchar(15)	      NO		      NULL	
grade	varchar(15)	      NO		      NULL	
phone	varchar(20)	      NO		      NULL	  
```

#### TRUNCATE: 데이터 베이스 오브젝트 내용 삭제
* 테이블 내용 삭제 확인을 위해 내용 삽입
```sql
INSERT INTO student(name, phone, grade) VALUES("kim", "01012341234", "sophomore");
INSERT INTO student(name, phone, grade) VALUES("lee", "01012341111", "junior");
SELECT * FROM student;
```
결과
```
id	name   grade	    phone
1	kim	   sophomore	01012341234
2	lee	   junior	    01012341111
```

* TRUNCATE 후 STUDENT의 컬럼 조회는 안되지만(내용이 삭제되었기 때문), TABLE은 남아있음
```sql
TRUNCATE TABLE student;
EXPLAIN student;
SELECT * FROM student;
```
결과
```
Field	    Type	    Null	Key	Default	Extra
id	         int	      NO	PRI	NULL	auto_increment
name	varchar(15)	      NO		NULL	
grade	varchar(15)	      NO		NULL	
phone	varchar(20)	      NO		NULL 
```

#### DROP: 데이터 베이스 오브젝트 삭제

* DROP 한 후에는 테이블 자체가 삭제되었기 때문에, 조회하려고 하면 오류가 뜬다.
```sql
DROP TABLE student;
EXPLAIN student;
```
결과
```
line 31: Table 'test.student' doesn't exist
```

#### TRUNCATE, DELETE, DROP의 차이점

![image](https://user-images.githubusercontent.com/33820372/97026896-fb46db00-1594-11eb-8ecb-4408e2d264a7.png)
DELETE, TRUNCATE, DROP 차이 (출처: 위키독스 예제로 배우는 ORACLE)

DELETE는 데이터가 지워지지만 테이블의 용량은 그대로이다. 원하는 데이터만 지울수 있고, 삭제 후 되돌리기가 가능하다.  
TRUNCATE는 테이블 내용 자체를 밀어버린다. 삭제 후 되돌릴 수 없다.  
DROP은 테이블 전체를 삭제해서 공간 자체를 밀어버린다. 삭제 후 되돌릴 수 없다.
