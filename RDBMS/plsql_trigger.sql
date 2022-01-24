---procedure
create or replace procedure p1(a number,b number)
is
    c number(3);
begin
    c:=a+b;
    dbms_output.put_line(c);
end;
/
---to execute procedure
exec p1


---function
create or replace function f1(a number,b number)
return number
is
    c number(3);
begin
    c:=a+b;
    return c;
end;
/

---plsql/non stored
set serveroutput on
declare
    a varchar2(10);
    b varchar2(10);
begin
    a:='&a';
    b:='&b';
    dbms_output.put_line('full name is: ' || a ||' '|| b);
end;
/



---to execute funcation
select f1(1,5) from dual;

---to execute funcation using procedure
begin
    dbms_output.put_line(f1(10,20));
end;
/

declare
    a number(3);
    b number(3);
begin
    a:=&a;
    b:=&b;
    dbms_output.put_line(f1(a,b));
end;
/


---
create or replace procedure p1(a varchar2,b varchar2)
is
begin
    dbms_output.put_line('full name is: ' || a ||' '|| b);
end;
/


---function
create or replace function f1(a varchar2,b varchar2)
return varchar2
is
begin
   return (a||' '||b);
end;
/


---to retireve function/procedure information
select name from user_source;

select text from user_source where name='P1' AND type='PROCEDURE' order by line;

drop PROCEDURE p1;
drop function f1;

---triggers
create table demos
(
    no number(3)
);

set serveroutput on
insert into demos values(1);
create or replace trigger tridemo
    after insert on demos
begin   
    dbms_output.put_line('Record inserted');
end;
/