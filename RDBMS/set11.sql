create table TRAIN_MASTER
(
    TRAIN_NUMBER VARCHAR2(6) CHECK((TRAIN_NUMBER LIKE '%DN') OR (TRAIN_NUMBER LIKE '%UP')),
    TRAIN_NAME VARCHAR2(25) NOT NULL,
    ARRIVAL_TIME DATE NOT NULL,
    DEPARTURE_TIME DATE NOT NULL,
    NO_OF_HOURS NUMBER(5,2) NOT NULL,
    SOURCE_STATION VARCHAR2(25) NOT NULL,
    END_STATION VARCHAR2(25) NOT NULL,
    PRIMARY KEY(TRAIN_NUMBER)
);

insert into TRAIN_MASTER values('9012DN','RAJDHANI',
(TO_DATE('1-NOV-2021 12.35.10 PM','DD-MM-YYYY HH.MI.SS PM')),
(TO_DATE('1-NOV-2021 2.35.10 PM','DD-MM-YYYY HH.MI.SS PM')),
2,'DELHI','AGRA');

insert into TRAIN_MASTER values('3214UP','MALDHANI',
(TO_DATE('2-NOV-2021 2.35.10 AM','DD-MM-YYYY HH.MI.SS PM')),
(TO_DATE('2-NOV-2021 4.35.10 AM','DD-MM-YYYY HH.MI.SS PM')),
2,'JAMMU','KASHMIR');

---to select data from "TO_DATE('2-NOV-2021 2.35.10 AM','DD-MM-YYYY HH.MI.SS PM')".
select 
ARRIVAL_TIME,to_char(ARRIVAL_TIME,'YYYY-MM-DD'),
to_char(ARRIVAL_TIME,'HH24.MI.SS')
from TRAIN_MASTER;


create table PASSENGER_DETAILS
(
    TICKET_NUMBER NUMBER(5),
    TRAIN_NUMBER VARCHAR2(6) REFERENCES TRAIN_MASTER(TRAIN_NUMBER) ON DELETE CASCADE,
    SEAT_NUMBER NUMBER(2) NOT NULL,
    PASSENGER_NAME VARCHAR2(35) NOT NULL,
    AGE NUMBER(2) NOT NULL,
    GENDER CHAR(1) CHECK(GENDER IN('M','F')),
    TRAVEL_DATE DATE,
    CLASS VARCHAR2(4) CHECK(CLASS IN('IA','IIA','IIIA','IC','II'))
);

insert into PASSENGER_DETAILS values(1,'9012DN',30,'BHURO',28,'M','1-NOV-2021','IA');
insert into PASSENGER_DETAILS values(2,'3214UP',20,'BHAI',25,'M','2-NOV-2021','IC');


create table TRAIN_SEAT_MASTER
(
    TRAIN_NUMBER VARCHAR2(6) REFERENCES TRAIN_MASTER(TRAIN_NUMBER) ON DELETE CASCADE,
    CLASS VARCHAR2(4) CHECK(CLASS IN('IA','IIA','IIIA','IC','II')),
    TOTAL_SEATS NUMBER(2) CHECK(TOTAL_SEATS>=25 AND TOTAL_SEATS<=90)
);

insert into TRAIN_SEAT_MASTER values('9012DN','IA',25);
insert into TRAIN_SEAT_MASTER values('9012DN','II',45);
insert into TRAIN_SEAT_MASTER values('3214UP','IC',35);
insert into TRAIN_SEAT_MASTER values('9012DN','IIA',50);


create table TRAIN_DAY_MASTER
(
    TRAIN_NUMBER VARCHAR2(6) REFERENCES TRAIN_MASTER(TRAIN_NUMBER) ON DELETE CASCADE,
    DAY VARCHAR2(3) CHECK(DAY IN('MON','TUE','WED','THU','FRI','SAT','SUN'))
);

insert into TRAIN_DAY_MASTER values('9012DN','MON');
insert into TRAIN_DAY_MASTER values('9012DN','TUE');

insert into TRAIN_DAY_MASTER values('3214UP','WED');
insert into TRAIN_DAY_MASTER values('3214UP','TUE');


select * from TRAIN_MASTER;
select * from TRAIN_DAY_MASTER;

---1 Give all the train nanes starting from “Bombay” and going to “Ahmedabad” on Tuesday and Wednesday.
select tm.TRAIN_NAME
from 
TRAIN_MASTER tm, TRAIN_DAY_MASTER tdm
where 
tm.TRAIN_NUMBER=tdm.TRAIN_NUMBER and
(tm.SOURCE_STATION='JAMMU' and tm.END_STATION='KASHMIR') and 
tdm.TRAIN_NUMBER in(select TRAIN_NUMBER from TRAIN_DAY_MASTER where DAY='WED' and TRAIN_NUMBER in
(select TRAIN_NUMBER from TRAIN_DAY_MASTER where DAY='TUE'));
---or
select TRAIN_NAME from TRAIN_MASTER where 
TRAIN_NUMBER in(select TRAIN_NUMBER from TRAIN_DAY_MASTER where DAY='WED' and TRAIN_NUMBER in
(select TRAIN_NUMBER from TRAIN_DAY_MASTER where DAY='TUE')) and (SOURCE_STATION='JAMMU' and END_STATION='KASHMIR');


---2 List all trains which is available on Sunday.
select TRAIN_NAME,TRAIN_NUMBER from TRAIN_MASTER where 
TRAIN_NUMBER in(select TRAIN_NUMBER from TRAIN_DAY_MASTER where DAY='MON');


---3 Give classwise seat availability on 10-June-2018 for train 9012DN
select pd.class,(tsm.TOTAL_SEATS-count(pd.TICKET_NUMBER)) as AVAILABLE_SEAT
from 
PASSENGER_DETAILS pd, TRAIN_SEAT_MASTER tsm
where pd.TRAIN_NUMBER=tsm.TRAIN_NUMBER and
pd.CLASS=tsm.CLASS and
pd.TRAIN_NUMBER='9012DN' and pd.TRAVEL_DATE='1-NOV-2021'
group by pd.CLASS,tsm.Total_Seats;


---4 List total seats classwise for train running on thrusday.
select tsm.CLASS,tsm.TOTAL_SEATS as Total_Seat from 
TRAIN_SEAT_MASTER tsm, TRAIN_DAY_MASTER tdm
where
tdm.TRAIN_NUMBER=tsm.TRAIN_NUMBER and
tdm.DAY='TUE';


---5 List train names which have no sleeper class.
select tm.TRAIN_NAME
from TRAIN_MASTER tm, PASSENGER_DETAILS pd 
where tm.TRAIN_NUMBER=pd.TRAIN_NUMBER and
CLASS NOT in('sleeper class');


---6 List train number which run on Monday during 8:00: am to 1:00pm.
select tm.TRAIN_NUMBER 
from 
TRAIN_MASTER tm, TRAIN_DAY_MASTER tdm
where (to_char(ARRIVAL_TIME,'HH')>=12 or
to_char(DEPARTURE_TIME,'HH')<=04) and 
tdm.DAY='MON' and
tm.TRAIN_NUMBER=tdm.TRAIN_NUMBER;
