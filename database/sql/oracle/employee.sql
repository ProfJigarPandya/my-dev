select sysdate
  from dual;

create table employees (
   employee_id number primary key,
   first_name  varchar2(50),
   last_name   varchar2(50) not null
);

insert into employees (
   employee_id,
   first_name,
   last_name
) values ( 1,
           'John',
           'Doe' );

commit;

select * from employees;
