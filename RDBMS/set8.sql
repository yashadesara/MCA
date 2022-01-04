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





