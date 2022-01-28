create table DEPTS
(  
    deptno int PRIMARY KEY,
    DNAME VARCHAR(10)
);

insert into DEPTS values(1,'DEPTS1');
insert into DEPTS values(2,'DEPTS2');
insert into DEPTS values(3,'DEPTS3');

create table EMPMAST
(
    empno int PRIMARY KEY,
    name VARCHAR(8),
    pfno int,
    empbasic number(6),
    deptno int REFERENCES DEPTS(deptno),
    designation VARCHAR(10)
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
	select empno,name,empbasic,DEPTS.DNAME from EMPMAST,DEPTS where EMPMAST.deptno=DEPTS.deptno;
	HRA number(8,2);
	DA number(8,2);
	Medical number(8,2);
	PF number(8,2);
	amt number(8,2);
begin	
	dbms_output.put_line(rpad('-',100,'-'));
	dbms_output.put_line(upper(
			rpad('empno',10)|| rpad('ename',10)|| rpad('sal',10)|| 
			rpad('HRA',10)||rpad('DA',10)||rpad('Medical',10)||rpad('PF',10)||rpad('amt',10)
		));
	dbms_output.put_line(rpad('-',100,'-'));
	for r in c1 loop
		HRA := (r.empbasic*15)/100;
		DA := (r.empbasic*50)/100;
		Medical := 100;
		PF := (r.empbasic*8.33)/100;
		amt := (r.empbasic+HRA+DA+Medical)-PF;
			dbms_output.put_line(upper(
				rpad(r.empno,10)|| rpad(r.name,10)|| rpad(r.empbasic,10)|| 
				rpad(HRA,10)||rpad(DA,10)||rpad(Medical,10)||rpad(PF,10)||rpad(amt,10)
			)); 
	end loop;
	dbms_output.put_line(rpad('-',100,'-'));
end;
/