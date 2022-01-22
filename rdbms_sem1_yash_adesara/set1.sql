create table DEPARTMENT1
(
	dept_no number,
	dept_name varchar2(20),
	location varchar2(2)
);


insert into DEPARTMENT1 values(10,'Account','NY')
insert into DEPARTMENT1 values(20,'HR','NY')
insert into DEPARTMENT1 values(30,'Production','DL')
insert into DEPARTMENT1 values(40,'Sales','NY')
insert into DEPARTMENT1 values(50,'EDP','MU')
insert into DEPARTMENT1 values(60,'TRG','')
insert into DEPARTMENT1 values(110,'RND','AH')


---4 Display all records of Department table 
select * from DEPARTMENT1;

---5  Display all department belonging to location 'NY'
select * from DEPARTMENT1 where location='jm' ;

---6 Display details of Department 10
select * from DEPARTMENT1 where dept_no='10' ;

---7 List all department names starting with 'A' 
select * from DEPARTMENT1 where dept_name LIKE 'A%' ;

---8 List all departments whose number is between 1 and 100
select * from DEPARTMENT1 where dept_no BETWEEN 1 and 100;

---9 Delete 'TRG' department 
delete from DEPARTMENT1 where DEPT_NAME='trg';

---10 Change department name 'EDP' to 'IT
update DEPARTMENT1 set DEPT_NAME='it' where DEPT_NAME='har';