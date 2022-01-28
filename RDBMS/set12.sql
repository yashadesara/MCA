create table CUSTOMERR
(
    cid int PRIMARY KEY,
    fname VARCHAR2(10),
    lname VARCHAR2(10),
    city VARCHAR2(10),
    country VARCHAR2(10),
    phone number(10)
);

insert into CUSTOMERR values(1,'XXX','YYY','JAM','IND',9293998880);
insert into CUSTOMERR values(2,'AAA','CCC','RJKT','IND',1295998880);
insert into CUSTOMERR values(3,'BBB','DDD','SURAT','IND',2294928880);
insert into CUSTOMERR values(4,'CCC','GDD','LS','US',235928880);
insert into CUSTOMERR values(5,'GGG','DGD','LV','US',457880);

create table ORDERR
(
    oid int PRIMARY KEY,
    oDate date,
    oNumber number(10),
    cid int REFERENCES CUSTOMERR(cid),
    oTotalAmount number(10)
);

insert into ORDERR values(1,'21-AUG-2021',123,1,10000);
insert into ORDERR values(2,'22-SEP-2021',456,2,20000);
insert into ORDERR values(3,'23-OCT-2021',789,3,30000);
insert into ORDERR values(4,'24-OCT-2021',234,3,2000);


---1 List the number of customers in each country. Only include countries with more than 100 customers
select count(fname),country from CUSTOMERR group by country having count(fname)>2;


---2 List the number of customers in each country, except China, sorted high to low.
-- Only include countries with 5 or more customers
select count(fname),country from CUSTOMERR where country not in('US') group by country order by country DESC;


---3 List all customers with average orders between Rs.5000 and Rs.6500.
select fname from CUSTOMERR where cid in(
select cid from ORDERR group by cid having avg(oTotalAmount) between 5000 and 10000);


-- 4. Create a trigger that executes whenever country is updated in CUSTOMER table
set serveroutput on
create or replace trigger tricountry
    before insert or update or delete on CUSTOMERR
    for each row
begin
    dbms_output.put_line('you are updating record customer'||
        :OLD.country || 'to'||:NEW.country||' country in customer');
end;
/


-- 5. Create a function to return customer with maximum orders.
create or replace function f1
return varchar2
is  
    f CUSTOMERR.fname%type;
begin
    select fname into f from CUSTOMERR where cid in(select max(cid) from ORDERR);
    return f;
end;
/
select f1() from dual;

-- 6. Create a procedure to display month names of dates of ORDER table. The month
-- names should be unique.
create or replace procedure p1
is
cursor c1
is
    select distinct to_char(oDate,'MON') as mon from ORDERR;
begin
dbms_output.put_line(Rpad('-',10,'-'));
dbms_output.put_line(
    Rpad('MONTH',15)
);
dbms_output.put_line(Rpad('-',10,'-'));
for r in c1 loop
    dbms_output.put_line(
        Rpad(r.mon,15)
    );
    end loop;
end;
/
