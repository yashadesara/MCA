create table depa
(
    dno int,
    dname varchar(10),
    PRIMARY KEY(dno)
);
insert into depa values(1,'MCA');
insert into depa values(2,'BCA');

create table faculty
(
    dno int,
    fno int,
    fname varchar(10),
    PRIMARY KEY(fno),
    FOREIGN KEY (dno) REFERENCES depa(dno)
);
insert into faculty values(1,1,'BR');
insert into faculty values(1,2,'BJ');
insert into faculty values(1,3,'NL');
insert into faculty values(2,4,'JJ');

create table sem
(
    sno int,
    PRIMARY KEY(sno)
);
insert into sem values(1);
insert into sem values(2);
insert into sem values(3);

create table sub
(
    sub_id int,
    sname varchar(10),
    PRIMARY KEY(sub_id)
);
insert into sub values(1,'RDBMS');
insert into sub values(2,'JS');
insert into sub values(3,'PHP');
insert into sub values(4,'JAVA');

create table slot
(
    slot_id int,
    start_date date,
    end_date date,
    PRIMARY KEY(slot_id)
);
insert into slot values(1,to_date('09:00 AM','HH:MI PM'),to_date('10:00 AM','HH:MI PM'));
insert into slot values(2,to_date('10:00 AM','HH:MI PM'),to_date('11:00 AM','HH:MI PM'));
insert into slot values(3,to_date('11:00 AM','HH:MI PM'),to_date('12:00 AM','HH:MI PM'));

update slot set start_date=to_date('11:00 PM','HH:MI PM') where slot_id=3;
update slot set end_date=to_date('12:00 PM','HH:MI PM') where slot_id=3;

truncate table timetable;
truncate table slot;

create table timetable
(
    tno int,
    dno int,
    fno int,
    sno int,
    sub_id int,
    slot_id int,
    lecday varchar(3) check (lecday in('Mon','Tue','Wed','Thu','Fri','Sat')),
    typeoflec varchar(10) check (typeoflec in('Practical','Theory')),
    PRIMARY KEY(tno),
    FOREIGN KEY (dno) REFERENCES depa(dno),
    FOREIGN KEY (fno) REFERENCES faculty(fno),
    FOREIGN KEY (sno) REFERENCES sem(sno),
    FOREIGN KEY (sub_id) REFERENCES sub(sub_id),
    FOREIGN KEY (slot_id) REFERENCES slot(slot_id)
);

insert into timetable values(1,1,1,1,1,1,'Mon','Practical');
insert into timetable values(2,1,3,1,4,2,'Tue','Theory');
insert into timetable values(3,1,3,1,4,3,'Wed','Theory');

DELETE from timetable where slot_id=3;

---
select s.sno as SEM, d.dname as DEPARTMENT, tt.lecday as DAY, su.sname as SUBJECT, tt.typeoflec, f.fname as FACULTY,TO_CHAR( start_date, 'HH24:MI' ) , TO_CHAR( end_date, 'HH24:MI' )
from sem s, depa d, timetable tt, sub su, faculty f, slot st
where
d.dno=f.dno and
d.dno=tt.dno and
d.dno=tt.dno and
f.fno=tt.fno and
s.sno=tt.sno and
st.slot_id=tt.slot_id and
su.sub_id=tt.sub_id;

---
select f.fname
from FACULTY f, timetable tt
where
f.fno=tt.fno and
tt.lecday='Mon' and
tt.start_lec='8:00' and
tt.end_lec='9:00';


