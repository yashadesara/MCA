create table app
(
	aid varchar2(10),
	aname varchar2(10)
);

--- modify datatype.
alter table app modify aid number(10);

--- add constraint.
alter table app add constraint aid check (aid like 'A%');

--- drop constraint.
alter table app drop constraint aid;

