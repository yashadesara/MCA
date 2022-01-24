create table DEPT
(  
    DNO int PRIMARY KEY,
    DNAME VARCHAR(10)
);

insert into DEPT values(1,'DEPT1');
insert into DEPT values(2,'DEPT2');
insert into DEPT values(3,'DEPT3');

create table EMPMAST
(
    empno int PRIMARY KEY,
    name VARCHAR(8),
    pfno int,
    empbasic number(6),
    deptno int REFERENCES DNO(DEPT),
    designation VARCHAR(10,
);
insert into EMPMAST values(1,'XYZ',1,30000,1,'CODER');
insert into EMPMAST values(2,'PQR',2,50000,2,'TESTER');
insert into EMPMAST values(3,'ABC',3,80000,3,'DEVELOPING');


-- EMPMAST (empno, name, pfno, empbasic, deptno, designation)
-- DEPT (DNO, DNAME)
-- Rules: 
-- HRA = 15% of basic
-- DA = 50% of basic
-- Medical = 100
-- PF = 8.33%of basic
-- Print Salary slip. Design your own format

Declare
	cursor c1 is 
	select empno,ename,sal,job,dept.name
	from emp,dept where emp.deptno=dept.deptno;
	HRA number(6,2);
	DA number(6,2);
	Medical number(6,2);
	PF number(6,2);
	amt number(6,2);
begin	
	dbms_output.put_line(rpad('-',100,'-'));
	dbms_output.put_line(upper(
			rpad('empno',10)|| rpad('ename',10)||
			rpad('job',10)|| rpad('sal',10)|| 
			rpad('HRA',10)||rpad('DA',10)||rpad('Medical',10)||rpad('PF',10)||rpad('amt',10)
		));
	dbms_output.put_line(rpad('-',100,'-'));
	for r in c1 loop
		HRA := (r.sal*15)/100;
		DA := (r.sal*50)/100;
		Medical := 100;
		PF := (r.sal*8.33)/100;
		amt := (r.sal+HRA+DA+Medical)-PF;
		
			dbms_output.put_line(upper(
				rpad(r.empno,10)|| rpad(r.ename,10)||
				rpad(r.job,10)|| rpad(r.sal,10)|| 
				rpad(HRA,10)||rpad(DA,10)||rpad(Medical,10)||rpad(PF,10)||rpad(amt,10)
			)); 
		
	end loop;
	dbms_output.put_line(rpad('-',100,'-'));
end;
/