create table STUDENT
(
    rollno int PRIMARY KEY,
    name varchar2(10),
    class varchar2(2),
    birthdate date
);

create table COURSE
(
    courseno int PRIMARY KEY,
    coursename varchar2(10),
    max_marks number,
    pass_marks number
);

create table SC
(
    rollno int REFERENCES STUDENT(rollno),
    courseno int REFERENCES COURSE(courseno),
    marks number CHECK(marks>=0 and marks<=100)
);



alter table sc add PRIMARY KEY(rollno,courseno);



insert into STUDENT (rollno,name,class,birthdate)values(1,'yash','A','27-AUG-2000');
insert into STUDENT (rollno,name,class,birthdate)values(2,'yashlo','A','28-AUG-2000');
insert into STUDENT (rollno,name,class,birthdate)values(3,'bhuro','B','22-AUG-2000');
insert into STUDENT (rollno,name,class,birthdate)values(4,'bhai','B','22-AUG-2000');
insert into STUDENT (rollno,name,class,birthdate)values(5,'Done','B','23-AUG-2000');
insert into STUDENT (rollno,name,class,birthdate)values(6,'Donee','A','23-AUG-1999');


insert into COURSE (courseno,coursename,max_marks,pass_marks)values(1,'MCA',100,35);
insert into COURSE (courseno,coursename,max_marks,pass_marks)values(2,'BCA',100,35);
insert into COURSE (courseno,coursename,max_marks,pass_marks)values(3,'MCA',100,35);
insert into COURSE (courseno,coursename,max_marks,pass_marks)values(4,'MCA',100,70);
insert into COURSE (courseno,coursename,max_marks,pass_marks)values(5,'BCA',100,30);
insert into COURSE (courseno,coursename,max_marks,pass_marks)values(6,'BCA',770,120);



insert into SC(rollno,courseno,marks)values(1,1,100);
insert into SC(rollno,courseno,marks)values(1,2,80);
insert into SC(rollno,courseno,marks)values(2,1,100);
insert into SC(rollno,courseno,marks)values(3,1,100);
insert into SC(rollno,courseno,marks)values(4,3,100);
insert into SC(rollno,courseno,marks)values(5,1,30);
insert into SC(rollno,courseno,marks)values(1,1,30);



update sc set marks=60 where rollno=3;
update sc set marks=70 where rollno=4;




-- 5. Display details of student who takes ‘Database Management System’ course
select
a.rollno, a.name, b.coursename, sc.rollno
from
STUDENT a,COURSE b, SC sc
where 
a.rollno=sc.rollno
and b.courseno=sc.courseno
and b.coursename='MCA';




-- 6. Display the names of students who have scored more than 70% in Computer
-- Networksand have not failed in any subject.
select distinct
a.name ,a.rollno, sc.marks
from
STUDENT a,COURSE b, SC sc
where 
a.rollno=sc.rollno
and b.coursename='MCA'
and sc.marks>80
and sc.rollno in(select rollno from sc where rollno not in
(select rollno from sc,course where marks<course.pass_marks));




-- 7. Display the average marks obtained by each student.
select
a.name, avg(marks)
from
STUDENT a, SC sc
where
a.rollno=sc.rollno
group by a.name;
//TRY THIS : min, max, sum, count, avg



-- 8. Select all courses where passing marks are more than 30% of average maximum mark.
select * from COURSE
where pass_marks>(select avg(max_marks)*0.30 from COURSE);


-- 9. Display details of students who are born in 1980 or 1982.
select * from STUDENT where to_char(birthdate,'YYYY') IN ('2000');


-- 10. Create a view that displays student courseno and its corresponding marks.
create view v1 as
select c.coursename,sc.courseno,sc.marks
from
COURSE C,SC sc
where
c.courseno=sc.courseno;





































