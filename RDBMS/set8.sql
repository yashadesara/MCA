create table SCREEN
(
    screen_id VARCHAR2(10)CHECK(screen_id LIKE 'S%'),
    location VARCHAR2(2)CHECK(location in('FF','SF','TF')),
    seating_cap number(5) NOT NULL,
    PRIMARY KEY(screen_id)
);

insert into SCREEN values('S1','FF',80);
insert into SCREEN values('S2','SF',70);
insert into SCREEN values('S3','TF',60);
insert into SCREEN values('S4','FF',50);
insert into SCREEN values('S5','SF',40);
insert into SCREEN values('S6','SF',50);


create table MOVIE
(
    movie_id int PRIMARY KEY,
    movie_name VARCHAR2(15) UNIQUE,
    date_of_release date
);

insert into MOVIE values(1,'MOVIE 1','21-AUG-2021');
insert into MOVIE values(2,'MOVIE 2','22-AUG-2021');
insert into MOVIE values(3,'MOVIE 3','23-AUG-2021');
insert into MOVIE values(4,'MOVIE 4','24-AUG-2021');
insert into MOVIE values(5,'MOVIE 5','25-AUG-2021');
insert into MOVIE values(6,'star wars','28-FEB-2005');
insert into MOVIE values(7,'star wars III','18-FEB-2005');
insert into MOVIE values(8,'HELLO','12-JAN-2022');


create table CURR
(
    screen_id VARCHAR2(10) REFERENCES SCREEN(screen_id),
    movie_id int REFERENCES MOVIE(movie_id),
    date_of_arrival date,
    date_of_closure date
);

insert into CURR values('S1',1,'21-AUG-2021','11-SEP-2021');
insert into CURR values('S2',2,'22-AUG-2021','12-SEP-2021');
insert into CURR values('S3',3,'23-AUG-2021','13-SEP-2021');
insert into CURR values('S4',4,'24-AUG-2021','14-SEP-2021');
insert into CURR values('S4',5,'18-AUG-2021','28-SEP-2021');
insert into CURR values('S5',5,'25-AUG-2021','15-SEP-2021');


select * from SCREEN;
select * from MOVIE;
select * from CURR;


---1. Get the name of movie which has run the longest in the multiplex so far.
select * from MOVIE where movie_id=(select movie_id from
(select movie_id,(date_of_closure-date_of_arrival) as a from CURR 
order by a desc) where rownum=1);



---2. Get the average duration of a movie on screen number ‘S4’.
select screen_id,avg(date_of_closure-date_of_arrival) as Avereage_Duration from CURR 
where screen_id='S4' group by screen_id;



---3. Get the details of movie that closed on date 24-november-2004.
select * from MOVIE where movie_id in
(select movie_id from CURR where date_of_closure = '20-SEP-2021');



---4. Movie ‘star wars III ‘was released in the 7th week of 2005. Find out the date of its release considering that a movie releases only on Friday.
select * from movie
where 
to_char(date_of_release,'IW')=7 and
to_char(date_of_release,'YYYY')=2005 and
trim(to_char(date_of_release,'DAY'))='FRIDAY';


---5. Get the full outer join of the relations screen and current.
select s.*, c.*
from SCREEN s FULL OUTER JOIN CURR c on
s.screen_id=c.screen_id;


---6 Write a PL/SQL function which will count total number of day’s horror movie last longer.
create or replace function f1
return number
is  
    TOTL number(5);
begin
    select (date_of_closure-date_of_arrival) INTO TOTL 
    from 
    CURR 
    where movie_id in(select movie_id from movie where movie_name='MOVIE 1');
    return (TOTL);
end;
/
--- to run select f1 from dual;

--- with argument.
create or replace function f1(mname VARCHAR2)
return number
is  
    TOTL number(5);
begin
    select (date_of_closure-date_of_arrival) INTO TOTL 
    from 
    CURR 
    where movie_id in(select movie_id from movie where movie_name=mname);
    return (TOTL);
end;
/

---7 Write a PL/SQL procedure that will display movie which is going to release today.
create or replace procedure p1
is
cursor c1
is
select movie_id, movie_name, date_of_release from 
movie where 
date_of_release=(select to_char(sysdate,'DD-MON-YY') from dual);
begin
    for r in c1 loop
        dbms_output.put_line(
        Rpad(r.movie_id,15) ||
        Rpad(r.movie_name,15) ||
        Rpad(r.date_of_release,15)
        );
    end loop;
end;
/


-- 8. Write a trigger which will not allow to insert/update in current table if Date_of_arrival 
-- is less than date_of_closure.

create or replace trigger tricurr
    before insert or update or delete on CURR
    for each row
declare
    msg varchar2(100);
begin   
    msg:='';
    if  :new.date_of_arrival < :new.date_of_closure then
        if inserting then
            msg:=' insert ';
        elsif updating then
            msg:=' update ';
        else
           msg:=' delete ';
        end if;
        raise_application_error(-20000,'you can not' ||msg|| 'when date of arrival is less than date of closure date');
    end if;
end;
/


