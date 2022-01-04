create table EMPLOYEE
(
    emp_id int PRIMARY KEY,
    emp_name VARCHAR2(10),
    birth_date date,
    gender VARCHAR2(10)CHECK(gender in('Male','Female')),
    dept_no int REFERENCES DEPART(dept_no),
    address VARCHAR2(20),
    designation VARCHAR2(20),
    salary number(10),
    experience VARCHAR2(20),
    email VARCHAR2(10)CHECK(email LIKE '%_@%_._%')
);


create table DEPART
(
    dept_no int PRIMARY KEY,
    dept_name VARCHAR2(20),
    total_employees number(10),
    location VARCHAR2(20)
);


create table PROJECT
(
    proj_id int PRIMARY KEY,
    type_of_project VARCHAR2(10),
    status VARCHAR2(10),
    start_date date,
    emp_id int REFERENCES EMPLOYEE(emp_id)
);




insert into DEPART values(1,'TECHNOLOGY',5,'DUBAI');
insert into DEPART values(2,'TECHNICAL',15,'LA');
insert into DEPART values(3,'IT',18,'AME');
insert into DEPART values(4,'DEVELOPING',20,'AD');
insert into DEPART values(5,'CODING',22,'JA');
insert into DEPART values(6,'TESTING',25,'RJ');
insert into DEPART values(7,'ING',1,'RJK');


insert into EMPLOYEE values(1,'YASH','26-AUG-2000','Male',1,'JAM','DEVELOPER',20000,'TWO YEARS','ok@g.com');
insert into EMPLOYEE values(2,'HAR','27-AUG-2000','Male',2,'RJ','TESTER',30000,'THREE YEARS','ok@g.com');
insert into EMPLOYEE values(3,'PRI','28-AUG-2000','Male',3,'BHAV','DESI',40000,'FOUR YEARS','ok@g.com');
insert into EMPLOYEE values(4,'MET','29-AUG-2000','Male',4,'AHE','CODE',50000,'FIVE YEARS','ok@g.com');
insert into EMPLOYEE values(5,'DAT','30-AUG-2000','Male',5,'DUB','POP',60000,'SIX YEARS','ok@g.com');
insert into EMPLOYEE values(6,'OKK','31-AUG-2000','Male',6,'DUBA','POPS',70000,'SEVEN YEARS','ok@g.ccom');
insert into EMPLOYEE values(7,'BHURI','11-AUG-2000','Female',7,'DUBAII','POPS',80000,'eight YEARS','ok@g.com');
insert into EMPLOYEE values(8,'BHUROO','15-NOV-2021','Male',1,'DUBAII','POPSS',45000,'eight YEARS','ok@g.com');


insert into PROJECT values(1,'project1','Running','20-MAR-2005',1);
insert into PROJECT values(2,'project2','Pending','21-MAR-2005',2);
insert into PROJECT values(3,'project3','Running','22-MAR-2005',3);
insert into PROJECT values(4,'project4','Pending','23-MAR-2005',4);
insert into PROJECT values(5,'project5','Running','24-MAR-2005',5);
insert into PROJECT values(6,'project6','Pending','25-MAR-2005',6);



-- 1. Delete the department whose total number of employees less than 1. 
delete from DEPART where total_employees<1;

-- 2. Display the names and the designation of all female employee in descending order.
select emp_name,designation from EMPLOYEE where gender='Female' order by emp_id DESC;

-- 3. Display the names of all the employees who names starts with ‘A’ ends with ‘A’.
select emp_name from EMPLOYEE where emp_name LIKE 'O%K'


-- 4. Find the name of employee and salary for those who had obtain minimum salary.
select emp_name,salary 
from EMPLOYEE
where salary=
(select min(salary) from EMPLOYEE);


-- 5. Add 10% raise in salary of all employees whose department is ‘CIVIL’.
update EMPLOYEE set salary=salary+(salary*0.10)
where dept_no=
(select dept_no from DEPART where dept_name='TECHNOLOGY');



-- 6. Count total number of employees of ‘MCA’ department.
select count(emp_name) from EMPLOYEE
where dept_no=(
select dept_no from DEPART where dept_name='TECHNOLOGY');


-- 7. List all employees who born in the current month
select emp_name,to_char(birth_date,'MON') 
from EMPLOYEE
where to_char(birth_date,'MON')=(
select to_char(sysdate,'MON') from dual);


-- 8. Print the record of employee and dept table as “Employee works in department ‘CE’. 
select e.emp_name || ' works in ' || d.dept_name
from EMPLOYEE e, DEPART d
where e.dept_no = d.dept_no;


-- 9. List names of employees who are fresher’s(less than 1 year of experience).
select emp_name from EMPLOYEE where experience<='ONE YEAR';


-- 10. List department wise names of employees who has more than 5 years of experience. 
select e.emp_name,d.dept_name
from EMPLOYEE e,DEPART d
where 
e.experience<='FIVE YEARS' AND
e.dept_no=d.dept_no;



























