create table DEPT
(  
    DNO int PRIMARY KEY,
    DNAME VARCHAR(10)
);

create table EMPMAST
(
    empno int PRIMARY KEY,
    name VARCHAR(8),
    pfno int,
    empbasic number(6),
    deptno int REFERENCES DNO(DEPT),
    designation VARCHAR(10,
);