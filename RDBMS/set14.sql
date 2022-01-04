create table EMP
(
    empno int PRIMARY KEY, 
    empnm VARCHAR2(10), 
    empadd VARCHAR2(10), 
    salary number(6), 
    date_birth date, 
    joindt date, 
    deptno number(5)
);


create table JOB
(
    jobid int PRIMARY KEY, 
    type_of_job VARCHAR2(10), 
    status VARCHAR2(10)
);


create table ITEM
(
    itemno int PRIMARY KEY, 
    name VARCHAR2(10), 
    color VARCHAR2(10), 
    weight number(5)
)

create table WORKER
(
    workerid int PRIMARY KEY,  
    name VARCHAR2(10), 
    wage_per_hour , 
    specialized_in VARCHAR2(10), 
    manager_id int
);
