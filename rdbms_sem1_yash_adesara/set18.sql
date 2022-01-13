create table BRANCH
(
    branch_no int PRIMARY KEY,
    area VARCHAR(10),
    city VARCHAR(10)
);

create table MEMBERS
(
    mno int PRIMARY KEY,
    name VARCHAR(10),
    branch_no int REFERENCES branch_no(BRANCH),
    salary number(6),
    manager_no int
);