create table Empl
(
	emp_id number PRIMARY KEY,
	emp_name varchar2(10),
	birth_date number(10),
	gender varchar2(10),
	dept_no number REFERENCES dept(dept_no),
	address varchar2(10),
	designation varchar2(10),
	salary number CHECK(salary>0),
	experience number,
	email varchar2(10)
);

insert into Empl(emp_id,emp_name,birth_date,gender,dept_no,address,designation,salary,experience,email)
values(1,'YASH',26,'Male',1,'DUBAI','manager',2000,2,'ogcom');
insert into Empl(emp_id,emp_name,birth_date,gender,dept_no,address,designation,salary,experience,email)
values(2,'YASH',26,'Male',2,'DUBAI','manager',4000,2,'ogcom');
insert into Empl(emp_id,emp_name,birth_date,gender,dept_no,address,designation,salary,experience,email)
values(3,'BHURI',26,'Female',3,'DUBAI','manager',5000,1,'ogcom');
insert into Empl(emp_id,emp_name,birth_date,gender,dept_no,address,designation,salary,experience,email)
values(4,'',27,'Female',4,'DUBAI','manager',6000,5,'ogcom');


create table dept
(
	dept_no number PRIMARY KEY,
	dept_name varchar2(5),
	location varchar2(10)
);
insert into dept(dept_no,dept_name,location)
	values(1,'IT','DUBAI'); 
insert into dept(dept_no,dept_name,location)
	values(2,'ITS','DUBAICITY');
insert into dept(dept_no,dept_name,location)
	values(3,'ITSC','DUBAICITY');
insert into dept(dept_no,dept_name,location)
	values(4,'ITSCS','DUBAICITYS');
insert into dept(dept_no,dept_name,location)
	values(5,'AITS','DUBAICITYS');





alter table dept add UNIQUE(dept_name);




alter table Empl add CHECK(designation in('manager', 'clerk', 'leader', 'analyst', 'designer', 'coder',
'tester'));



alter table Empl add CHECK(gender in('Male','Female');

---9. Delete the department whose loction is Ahmedabad
select * from dept where location='DUBAI';



---10. Display female employee list
select * from Empl where gender='Female';



-- 11. Display Departname wise employee Names
select 
e.emp_name,d.dept_name,e.dept_no
from 
Empl e,
dept d
where
e.dept_no=d.dept_no
order by d.dept_name;


-- 12. Find the names of the employee who has salary less than 5000 and greater than 2000.
select emp_name from Empl where salary BETWEEN 2000 and 5000;


-- 13. Display the names and the designation of all female employee in descending order.
select emp_name,designation where gender='Female' order by emp_name DESC;


-- 14. Display the names of all the employees who names starts with ‘A’ ends with ‘A’.
select emp_name from Empl where emp_name LIKE 'A%A';


-- 15. Find the name of employee and salary for those who had obtain minimum salary
select emp_name,salary 
from Empl
where salary=
(select min(salary) from Empl);


-- 16. Add 10% raise in salary of all employees whose department is ‘IT’.
update Empl set salary=salary+(salary*0.10)
where dept_no=
(select dept_no from dept where dept_name='IT');

-- or

select salary,salary*0.10,(salary+(salary*0.10)) new_salary, dept_no from Empl
where dept_no=(select dept_no from dept where dept_name='IT');


-- 17. Count total number of employees of ‘IT’ department.
select count(*) from Empl
where dept_no=(
select dept_no from dept where dept_name='IT');



update Empl set dept_no=1 where emp_id=2;


-- 18. List all employees who born in the current month.
select emp_name,to_char(birth_date,'MON') 
from Empl
where to_char(birth_date,'MON')=(
select to_char(sysdate,'MON') from dual);


-- 19. Print the record of employee and dept table as “Employee works in department
-- ‘MBA’.
select e.emp_name || ' works in ' || d.dept_name
from Empl e, dept d
where e.dept_no = d.dept_no;



-- 20. List names of employees who are fresher’s (less than 1 year of experience).
select emp_name from Empl where experience<=1;



-- 21. List department wise names of employees who has more than 5 years of experience.
select 
e.emp_name,d.dept_name,e.experience
from 
Empl e,
dept d
where
d.dept_no=e.dept_no and e.experience>=2;



-- 22. Crete Sequence to generate department ID
CREATE SEQUENCE dept_no
MINVALUE 1
START WITH 1
INCREMENT BY 1
CACHE 10;

select dept_no.nextval from dual;
select dept_no.currval from dual;
select dept_no.nextval from dual;


-- 23. List department having no employees
select 
dept_name from dept
where dept_no
not in(select dept_no from Empl); 

















