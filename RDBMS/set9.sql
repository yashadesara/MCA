CREATE TABLE APPLICANT(
    AID VARCHAR2(20) CHECK (AID LIKE 'A%'), 
    ANAME VARCHAR2(40) NOT NULL, 
    ADDR VARCHAR2(100) NOT NULL, 
    ABIRTH_DT DATE,
    primary key(AID)
    );

INSERT INTO APPLICANT VALUES('A123','x','ab','28-OCT-00');
INSERT INTO APPLICANT VALUES('A124','y','ac','19-FEB-99');    
INSERT INTO APPLICANT VALUES('A223','z','ad','28-SEP-98');
INSERT INTO APPLICANT VALUES('A111','w','ae','28-DEC-97');
INSERT INTO APPLICANT VALUES('A222','u','af','28-JAN-96');
INSERT INTO APPLICANT VALUES('A567','BHURO','af','28-JAN-96');


CREATE TABLE ENTRANCE_TEST(
    ETID NUMBER primary key, 
    ETNAME VARCHAR2(30) not NULL,  
    MAX_SCORE NUMBER, 
    CUT_SCORE NUMBER 
    );

INSERT INTO ENTRANCE_TEST VALUES(1,'CMAT',400,200);
INSERT INTO ENTRANCE_TEST VALUES(2,'ORACLE FUNDAMENTALS',100,85);   
INSERT INTO ENTRANCE_TEST VALUES(3,'NEET',400,200);
INSERT INTO ENTRANCE_TEST VALUES(4,'JEE',400,250);
INSERT INTO ENTRANCE_TEST VALUES(5,'TAT',400,300);
INSERT INTO ENTRANCE_TEST VALUES(6,'STAT',400,300);
INSERT INTO ENTRANCE_TEST VALUES(7,'STAT',400,300);
INSERT INTO ENTRANCE_TEST VALUES(8,'QTAT',400,300);

update ENTRANCE_TEST set ETNAME='STATATA' where ETID=7;

CREATE TABLE ETEST_CENTRE(
    ETCID NUMBER primary key, 
    LOCATION VARCHAR(20) not null, 
    INCHARGE VARCHAR2(20), 
    CAPACITY NUMBER(5)
    );


INSERT INTO ETEST_CENTRE VALUES(1,'JAM','IS',100);
INSERT INTO ETEST_CENTRE VALUES(2,'RAJ','ISP',80);
INSERT INTO ETEST_CENTRE VALUES(3,'POR','IP',60);
INSERT INTO ETEST_CENTRE VALUES(4,'JUN','PS',40);
INSERT INTO ETEST_CENTRE VALUES(5,'DHR','PI',20);
INSERT INTO ETEST_CENTRE VALUES(6,'DHRR','SPI',20); 

update ETEST_CENTRE set CAPACITY=3 where ETCID=6;

CREATE TABLE ETEST_DETAILS(
    AID VARCHAR2(10) REFERENCES APPLICANT(AID), 
    ETID NUMBER(5) REFERENCES ENTRANCE_TEST(ETID), 
    ETCID NUMBER(5) REFERENCES ETEST_CENTRE(ETCID), 
    ETEST_DT DATE,
    SCORE NUMBER(5) CHECK (SCORE > 0),
    primary key(AID,ETID)
    );

---or



INSERT INTO ETEST_DETAILS VALUES('A111',1,1,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A111',2,2,'10-NOV-21',20);
update etest_details set score=400 where AID='A111' and ETID=2 and ETCID=2;

INSERT INTO ETEST_DETAILS VALUES('A123',2,2,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A124',3,3,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A222',4,4,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A223',5,5,'10-NOV-21',380);

INSERT INTO APPLICANT VALUES('A223','z','ad','28-SEP-98');
INSERT INTO ETEST_DETAILS VALUES('A223',6,5,'10-SEP-21',380);

INSERT INTO ETEST_DETAILS VALUES('A567',6,6,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A567',7,6,'10-NOV-21',380);
INSERT INTO ETEST_DETAILS VALUES('A567',8,6,'10-NOV-21',380);

INSERT INTO ETEST_DETAILS VALUES('A111',8,6,'10-NOV-21',400);





update ETEST_DETAILS set SCORE=200 where AID='A567' and ETID=8;
update ETEST_DETAILS set SCORE=200 where AID='A567' and ETID=7;
update ETEST_DETAILS set ETEST_DT='15-NOV-21' where AID='A567' and ETID=8;
update ETEST_DETAILS set SCORE=20 where AID='A567' and ETID=6;



select * from APPLICANT;
select * from ENTRANCE_TEST order by ETID;
select * from ETEST_CENTRE;
select * from ETEST_DETAILS;

select AID,ETID,SCORE from ETEST_DETAILS order by ETID;


---1.Display test center details where no tests were conducted.
select * from ETEST_CENTRE where ETCID not in(select ETCID from ETEST_DETAILS);


---1.Display details about applicants who have the same score as that of Ajaykumar in ‘ORACLE FUNDAMENTALS’.
select a.ANAME,ed.SCORE
from APPLICANT a, ENTRANCE_TEST e, ETEST_DETAILS ed
where a.AID=ed.AID and
ed.ETID=e.ETID and
e.ETNAME='ORACLE FUNDAMENTALS' and
ed.SCORE=
(select ed.SCORE
from APPLICANT a, ENTRANCE_TEST e, ETEST_DETAILS ed
where a.AID=ed.AID and
ed.ETID=e.ETID and
e.ETNAME='ORACLE FUNDAMENTALS' and
a.ANAME='y');


---2. Display details of applicants who appeared for all tests.
select * from APPLICANT where AID in(
select distinct aid from etest_details 
where 
aid in(select aid from etest_details group by aid having count(etid)=
(select count(*) from ENTRANCE_TEST)) 
and etid in(select distinct etid from ENTRANCE_TEST));



---3. Display those tests where no applicant has failed.
select ETID,ETNAME from ENTRANCE_TEST where etid not in
(select ed.etid from ETEST_DETAILS ed,ENTRANCE_TEST et where ed.ETID=et.ETID and SCORE<CUT_SCORE);


---4. Display details of entrance test centers which had full attendance between 1st Oct 15 and 15th Oct 16.

select * from ETEST_CENTRE where (ETCID,CAPACITY) in (select ETCID,count(ETEST_DT) as Att from
etest_details where ETEST_DT between '10-NOV-21' and '15-NOV-21' group by ETCID);


---5. Display details of the applicants who scored more than the cut score in the tests they appeared in
select a.AID, ed.SCORE
from APPLICANT a, etest_details ed, ENTRANCE_TEST et
where
ed.ETID=et.ETID and 
a.AID=ed.AID and
ed.SCORE>et.CUT_SCORE;


---6. Display average and maximum score test wise of tests conducted at Mumbai.
select et.ETNAME,ec.LOCATION,avg(SCORE),max(SCORE)
from ENTRANCE_TEST et,ETEST_DETAILS ed,ETEST_CENTRE ec
where 
ed.ETID=et.ETID and
ec.ETCID=ed.ETCID and
ec.LOCATION='DHRR' group by ETNAME,LOCATION;


---7. Display the number of applicants who have appeared for each test, test center wise.
select count(a.aid), ec.ETCID, ec.LOCATION
from APPLICANT a, ETEST_CENTRE ec, ETEST_DETAILS ed
where 
a.aid=ed.aid and
ec.ETCID=ed.ETCID
group by ec.LOCATION, ec.ETCID;


---8. Display details about test centers where no tests have been conducted.
select * from ETEST_CENTRE where ETCID not in(select ETCID from ETEST_DETAILS);


---9. For tests, which have been conducted between 2-3-17 and 23-4-17, show details of the tests as well as the test centre.
select et.*, ec.*,ed.ETEST_DT
from 
ENTRANCE_TEST et, ETEST_CENTRE ec, ETEST_DETAILS ed
where 
et.ETID=ed.ETID and
ec.ETCID=ed.ETCID and
ed.ETEST_DT between '10-NOV-21' and '15-NOV-21';


---10. How many applicants appeared in the ‘ORACLE FUNDAMENTALS’ test at Chennai in the month of February?  
select a.ANAME, et.ETID, ed.ETEST_DT, ec.LOCATION
from APPLICANT a,ENTRANCE_TEST et, ETEST_DETAILS ed, ETEST_CENTRE ec
where
a.aid=ed.aid and
et.etid=ed.etid and
et.ETNAME='ORACLE FUNDAMENTALS' and
ec.LOCATION='RAJ' and
to_char(ed.ETEST_DT,'MON') = 'NOV';


---11. Display details about applicants who appeared for tests in the same month as the month in which they were born.  
select a.aid,ed.ETEST_DT
from APPLICANT a,ETEST_DETAILS ed
where
a.aid=ed.aid and
to_char(a.ABIRTH_DT,'MON') = to_char(ed.ETEST_DT,'MON');


---12. Display the details about APPLICANTS who have scored the highest in each test, test centre wise.
select ed.AID,ec.LOCATION,ed.SCORE,et.ETNAME
from ENTRANCE_TEST et, ETEST_DETAILS ed, ETEST_CENTRE ec
where
et.etid=ed.etid and
ed.ETCID=ec.ETCID and(ed.etid,ed.ETCID,ed.SCORE) in
(select etid,etcid,max(score) from etest_details
group by etid,etcid);


---13. Design a read only view, which has details about applicants and the tests that he has appeared for.
create view v2 as select ed.AID,et.ETNAME from ETEST_DETAILS ed,ENTRANCE_TEST et where ed.ETID=et.ETID;



-- 14. Write a procedure which will print maximum score centre wise.
create or replace procedure p1
is
cursor c1
is
select etcid,max(score)as score1 from ETEST_DETAILS group by ETCID;
begin
    dbms_output.put_line(
        Rpad('CENTRE ID',10) ||
        Rpad('SCORE',10)
    );
    for r in c1 loop
        dbms_output.put_line(
        Rpad(r.etcid,10) ||
        Rpad(r.score1,10)
        );
    end loop;
end;
/


-- 15. Write a procedure which will print details of entrance test.
create or replace procedure p1
is
    cursor c1
    is
    select ec.location, a.aid, ed.ETEST_DT, ed.score
    from
    ETEST_CENTRE ec, APPLICANT a, ETEST_DETAILS ed, ENTRANCE_TEST et
    where
    a.aid=ed.aid and
    et.ETID=ed.ETID and
    ec.ETCID=ed.etcid;
begin
    dbms_output.put_line('--------------------------------');
    dbms_output.put_line(
        Rpad('LOCATION',10) ||
        Rpad('AID',10) ||
        Rpad('ETEST_DATE',10) ||
        Rpad('SCORE',10)
    );
    dbms_output.put_line('--------------------------------');
    for r in c1 loop
            dbms_output.put_line(
            Rpad(r.location,10) ||
            Rpad(r.aid,10) ||
            Rpad(r.ETEST_DT,10) ||
            Rpad(r.score,10)
            );
    end loop;
end;
/

-- 15. Write a trigger which do not allow insertion / updation / deletion of Enterance test 
-- details on Sunday
create or replace trigger triet
    before insert or update or delete on ENTRANCE_TEST
    for each row
declare
    msg varchar2(100);
begin   
    msg:='';
    if  trim(to_char(sysdate,'DAY'))='MONDAY' then
        if inserting then
            msg:=' insert ';
        elsif updating then
            msg:=' update ';
        else
           msg:=' delete ';
        end if;
        raise_application_error(-20000,'you can not' ||msg|| 'on MONDAY');
    end if;
end;
/



