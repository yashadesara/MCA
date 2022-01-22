create table ACCOUNT
(
    AC_NO int PRIMARY KEY,
    NAME VARCHAR(10),
    AC_TYPE VARCHAR(10),
    BALANCE_AMT number(10),
    BALANCE_DATE date
);

create table TRANSACTION
(
    AC_NO int REFERENCES AC_NO(ACCOUNT),
    DATE date,
    TR_TYPE VARCHAR(10),
    AMOUNT number(10),
    PREV_BALANCE number(10),
    REMARK VARCHAR(10)
);