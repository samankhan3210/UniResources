/*Taks:01 Create table persons having personID as primary key, FirstName,LastName,Address,City and age as attributes. 
          Add 10 records into persons and create a savepoint after inserting five records. Update the record on personID=7 
          where FirstName=Erum and after updation it should be FirstName=Rida.Now Rollback the transaction to savepoint1 and see the changes.*/

create table persons (personID varchar2(10) primary key, first_name varchar2(25), last_name varchar2(25), address  varchar2(25), 
                      city varchar2(25), age number(10));
insert into persons values (1, 'Saman', 'Khan', '1234 address', 'Karachi', 21);
insert into persons values (2, 'Erum', 'Khan', '1234 address', 'Islamabad', 29);
insert into persons values (3, 'Hina', 'Khan', '1234 address', 'Karachi', 19);
insert into persons values (4, 'Anum', 'Khan', '1234 address', 'Peshawar', 12);
insert into persons values (5, 'Hermain', 'Qadir', '1234 address', 'Karachi', 22);
savepoint sp_1; 
select * from persons; 

insert into persons values (6, 'Anusha', 'Saad', '5678 address', 'Rawalpindi', 19);
insert into persons values (7, 'Erum', 'Erum', '5678 address', 'Karachi', 21);
insert into persons values (8, 'Areeb', 'Aqeel', '5678 address', 'Lahore', 18);
insert into persons values (9, 'Ahmed', 'Raza', '5678 address', 'Quetta', 18);
insert into persons values (10, 'Farjad', 'Farjad', '5678 address', 'Karachi', 18);
select * from persons; 

update persons set first_name='Rida' where personID=07 and first_name='Erum';
select * from persons; 
rollback to savepoint sp_1; 
select * from Persons;

/*Task:02 By using above persons table update a record on personID=8 and change the age from 28 to 30 then without commiting 
          change create a new session and update the record on PersonID=8 and set age=31. State what is the reason behind no 
          updataion.*/
update persons set age=23 where personID=03;
select * from persons; 
-- Since the update here hasn't been committed so other sessions cannot access the database which means that the database is locked for other sessions.