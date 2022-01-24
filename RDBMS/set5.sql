create table HOSTEL(
    hno number(10) PRIMARY KEY,
    hname VARCHAR2(20) NOT NULL,
    haddr VARCHAR2(20) NOT NULL,
    total_capacity number(10),
    warden VARCHAR2(20)
);

insert into HOSTEL values(1,'DELUX HOSTEL','RJKT CITY',10,'KESHWALA');
insert into HOSTEL values(2,'ECONOMY HOSTEL','JMGR CITY',8,'RAMWALA');
insert into HOSTEL values(3,'A ONE HOSTEL','AHMD CITY',5,'BHAIWALA');
insert into HOSTEL values(4,'B ONE HOSTEL','DUBAI CITY',15,'ATARWALA');
insert into HOSTEL values(5,'NEW HOSTEL','LS CITY',2,'WALA');

create table ROOM(
    hno number(10) REFERENCES HOSTEL(hno),
    rno number(10) NOT NULL,
    rtype VARCHAR2(20) NOT NULL,
    location VARCHAR2(20) NOT NULL,
    no_of_students number(10),
    status VARCHAR2(20),
    PRIMARY KEY(hno,rno)
);

insert into ROOM values (1,1,'ONE BAD','1 floor',1,'OCCUPIED');
insert into ROOM values(2,2,'DOUBLE BAD','1 floor',2,'OCCUPIED');
insert into ROOM values(1,3,'THREE BAD','1 floor',3,'OCCUPIED');
insert into ROOM values(1,4,'FOUR BAD','1 floor',4,'OCCUPIED');
insert into ROOM values(1,5,'FIVE BAD','1 floor',5,'OCCUPIED');
insert into ROOM values(1,6,'SIX BAD','1 floor',5,'vaccent');


create table CHARGES(
    hno number(10) REFERENCES HOSTEL(hno),
    rtype VARCHAR2(20) NOT NULL,
    charges number(20),
    PRIMARY KEY(hno,rtype)
);


insert into CHARGES values (1,'ONE BAD',10000);
insert into CHARGES values (2,'DOUBLE BAD',20000);
insert into CHARGES values (3,'THREE BAD',30000);
insert into CHARGES values (4,'FOUR BAD',40000);
insert into CHARGES values (5,'FIVE BAD',50000);


create table STUDENTS(
    sid int PRIMARY KEY,
    sname VARCHAR(20) NOT NULL,
    mobile_no number(10),
    gender VARCHAR(10)CHECK(gender in('Male','Female')),
    faculty VARCHAR(10) NOT NULL,
    dept VARCHAR(10) NOT NULL,
    class VARCHAR(10) NOT NULL,
    hno int REFERENCES HOSTEL(hno),
    rno int 
);



insert into STUDENTS values(1,'HARSHIT',99999999,'Male','BR','IT','A',1,1);
insert into STUDENTS values(2,'PRIYANK',99988999,'Male','BR','IT','B',2,2);
insert into STUDENTS values(3,'BHURO',99119999,'Male','BR','IT','A',3,1);
insert into STUDENTS values(4,'BRO',99333999,'Male','BR','IT','B',4,2);
insert into STUDENTS values(5,'BHAI',992229999,'Male','BR','IT','A',5,3);



create table FEES(
    sid int REFERENCES STUDENTS(sid),
    fdate date,
    famount number(10)
);


insert into FEES values(1,'27-AUG-2000',10000);
insert into FEES values(2,'17-AUG-2000',15000);
insert into FEES values(3,'07-AUG-2000',18000);
insert into FEES values(4,'25-AUG-2000',20000);
insert into FEES values(5,'21-AUG-2000',22000);



-- 1. Display the total number of rooms that are presently vacant
select count(status) from ROOM where status='vaccent';


-- 2. Display number of students of each faculty and department wise staying in each
-- -- hostel.
/*in aggregrate function COUNT* always use GROUP BY*/
select  s.faculty, s.dept, h.hname, count(*)
from STUDENTS s, HOSTEL h
where s.hno=h.hno 
group by faculty,dept,hname;


-- 3. Display hostels, which have at least one single-seated room
select h.hname 
from HOSTEL h, ROOM r
where 
r.rtype='ONE BAD' AND
h.hno=r.hno;


-- 4. Display the warden name and hostel address of students of Computer Science
-- department.

select h.warden, h.haddr, s.dept
from HOSTEL h, STUDENTS s
where
h.hno=s.hno AND
s.dept='IT';    

-- 5. Display those hostel details where single seated or double-seated rooms are vacant. 
select h.hname 
from HOSTEL h, ROOM r
where 
r.rtype in('ONE BAD','DOUBLE BAD') and
r.status='OCCUPIED' and
h.hno=r.hno
GROUP BY hname;



-- 6. Display details of hostels occupied by medical students
select h.hname
from HOSTEL h, ROOM r, STUDENTS s
where s.dept='IT' and
r.status='OCCUPIED' and
h.hno=r.hno and
r.rno=s.rno
GROUP BY hname;

-- 7. Display hostels, which are totally occupied to its fullest capacity
select hno,count(sid) from STUDENTS GROUP by hno;
select hno,total_capacity from HOSTEL;
    
select hname,total_capacity 
from HOSTEL 
where(hno,total_capacity) in (select hno,count(sid) from STUDENTS GROUP by hno); 


-- 8. List details about students who are staying in the double-seated rooms of Chanakya
-- Hostel.
select s.sname 
from HOSTEL h, ROOM r, STUDENTS s
where r.rno=s.rno and
h.hname='DELUX HOSTEL' and
r.rtype='DOUBLE BAD';


-- 9. Display the total number of students staying in each room type of each hostel.
select h.hname,r.rtype,count(r.no_of_students)
from HOSTEL h, ROOM r, STUDENTS s
where h.hno=r.hno and
r.rno=s.rno GROUP BY hname,rtype;


-- 10. Display details about students who have paid fees in the month of Nov. 2017.
select * from STUDENTS where sid in
    (select sid from FEES where to_char(fdate,'MON-YYYY')='NOV-2017');


-- 11. For those hostels where total capacity is more than 300, display details of students
-- -- studying in Science faculty.
select h.hname, s.sname
from HOSTEL h, STUDENTS s
where 
h.total_capacity>10 and
s.dept='IT';


-- 12. Display hostel details where there are at least 10 vacant rooms.
select hname 
from 
HOSTEL 
where hno in(select hno from ROOM where status='VACANT' GROUP by hno having count(rno)<=3);


-- 13. Display details of students who have still not paid fees.
select * from
STUDENTS where sid NOT in(select sid from FEES);


-- 14. Display those hostels where single-seated room is the costliest
SELECT a.* from hostel a,charges b where b.rtype='s' 
and 
a.hno=b.hno
AND
charges=(SELECT MAX(charges) from charges);


-- 15. Write a trigger which do not allow to insert or update student record if mobile_no length is less than 10 digits.
create or replace trigger tristu
    before insert or update on STUDENTS
    for each row
declare
    msg varchar2(100);
begin   
    msg:='';
    if length(:new.mobile_no)<10 then
        if inserting then
            msg:=' insert ';
        elsif updating then
            msg:=' update ';
        end if;
        raise_application_error(-20000,'you can not' ||msg|| 'if mobile_no length is less than 10 digits');
    end if;
end;
/
insert into STUDENTS values(6,'BHAIjaan',992229900,'Male','BR','IT','A',5,3);


--16 Write a PL/SQL block which will count total number of student’s gender wise. 
-- Male Students: 999 students Female Students: 999 student

declare
    tot_m number(5);
    tot_f number(5);
begin   
    select count(*) into tot_m from STUDENTS where gender='Male';
    select count(*) into tot_f from STUDENTS where gender='Female';
    dbms_output.put_line(tot_m);
    dbms_output.put_line(tot_f);
end;
/





















