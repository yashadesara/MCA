create table DEPT
(
    deptno int PRIMARY KEY,
    deptnm VARCHAR(10)
);

create table EMP
(
    empno int,
    empnm VARCHAR(8),
    empadd VARCHAR(10),
    salary number(6),
    date_birth date,
    joindt date,
    deptno int REFERENCES deptno(DEPT)
);