create table CUSTOMER
(
    cno int PRIMARY KEY,
    cust_name VARCHAR2(10) UNIQUE,
    cust_phone number(10) UNIQUE,
    location VARCHAR2(10),
    gender VARCHAR2(10) CHECK(gender in('Male','Female'))
);

create table ITEM
(
    itemno int PRIMARY KEY,
    itemname VARCHAR2(10) NOT NULL,
    color VARCHAR2(10),
    weight number(10),
    expire_date date,
    price number(5),
    shop_name VARCHAR2(10)
);

create table CUST_ITEM
(
    cno int REFERENCES CUSTOMER(cno),
    itemno int REFERENCES ITEM(itemno),
    quantity_purchased number(10) CHECK(quantity_purchased>0),
    date_purchased date
);


insert into CUSTOMER values(1,'BHURO',9999999999,'CO ROAD','Male');
insert into CUSTOMER values(2,'BHUR',9999999998,'LS ROAD','Male');
insert into CUSTOMER values(3,'BHU',9999999199,'CS ROAD','Male');


insert into ITEM values(1,'LAPTOP','RED',100,'26-AUG-2000',20000,'NEW SHOP');
insert into ITEM values(2,'SMARTPHONE','BLUE',200,'27-AUG-2000',30000,'OLD SHOP');
insert into ITEM values(3,'HANDSF','BLUE',200,'28-AUG-2000',30000,'OLD SHOP');


insert into CUST_ITEM values(1,1,10,'26-AUG-1991');
insert into CUST_ITEM values(2,2,20,'27-AUG-1992');
insert into CUST_ITEM values(3,3,30,'28-AUG-1993');
insert into CUST_ITEM values(3,2,25,'28-AUG-1993');
insert into CUST_ITEM values(1,3,30,'28-AUG-1993');
insert into CUST_ITEM values(1,2,25,'28-AUG-1993');

update item set expire_date='28-JAN-2021' where itemno=3;



-- 1. Delete the items whose price is more than 50000.
delete from ITEM where price>50000;


-- 2. Find the names of the customer who is located in same location as that of other 
-- customer.
select location,count(*) from CUSTOMER group by location having count(*)>=2;


-- 3. Display the names of items which is black, white & brown in color.
select itemname,color from item where color in('RED','BLUE');


-- 4. Display the names of all the items whose names lies between ‘p’ and‘s’.
select itemname from item where itemname BETWEEN 'G' and 'T';


-- 5. Find the item which is having less weight.
select * from item where weight in(
select min(weight) from item);


-- 6. Add one month more to those items whose item no =40.
update item set expire_date=add_months(expire_date,1)  where itemno=1;


-- 7. Count total number of items which is going to expire in next month---7
select count(*) from item where to_char(expire_date,'MON') = (   
select to_char(add_months(sysdate,1),'MON') from dual);


-- 8. List all customers whose phone number starts with ‘99’.
select cust_name from CUSTOMER where cust_phone like '99%';


-- 9. Display total value (qty*price) for all items.
select ci.quantity_purchased, i.price, (quantity_purchased*price) as total
from CUST_ITEM ci, ITEM i
where ci.itemno=i.itemno;


-- 10. List customer details who has purchased maximum number of items 
select * from CUSTOMER where cno in(
select cno from CUST_ITEM  group by cno having count(cno)=
(select max(ic) from (select cno,count(cno) as ic from CUST_ITEM
group by cno)));
---or
select * from CUSTOMER where cno in(select cno from
(select cno,count(cno) as ic from CUST_ITEM group by cno order by cno) where rownum=1);


-- 11. Display total price item wise.
select ci.quantity_purchased,(quantity_purchased*price) as total, i.price, i.itemname
from CUST_ITEM ci, ITEM i
where i.itemno=ci.itemno;


-- 12. List name of items, customer details and qty purchased.
select c.cust_name, i.itemname, ci.quantity_purchased
from CUSTOMER c, ITEM i, CUST_ITEM ci
where c.cno=ci.cno and
i.itemno=ci.itemno;

