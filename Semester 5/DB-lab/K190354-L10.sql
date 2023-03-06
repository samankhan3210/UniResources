create table Person(person_id int not null, person_name varchar(50) not null, PreviousName varchar(50) null, 
SameNameCount int null, constraint pk_Person primary key(person_id));

INSERT INTO Person (person_id, person_name) values (1, 'Saman');
INSERT INTO Person (person_id, person_name) values (2, 'Anusha');
INSERT INTO Person (person_id, person_name) values (3, 'Hermain');
INSERT INTO Person (person_id, person_name) values (4, 'Anum');
INSERT INTO Person (person_id, person_name) values (5, 'Hina');
INSERT INTO Person (person_id, person_name) values (6, 'Saman');
select * from Person;


create or replace trigger person_trigger_1
before update on Person for each row when (NEW.person_name is not null and NEW.person_name != OLD.person_name)
begin
    :NEW.PreviousName := :OLD.person_name;
end;


create or replace trigger person_trigger_2
after insert or delete on Person
begin
    update Person p set SameNameCount = (select count(*) from Person where person_name = p.person_name);
end;


create or replace trigger person_trigger_3 
after update of person_name on Person
begin
    update Person p set SameNameCount = (Select count(*) from Person where person_name = p.person_name);
end;


update Person set person_name = 'Erum' where person_id = 6;
delete from person where person_id=3;
INSERT INTO Person (person_id, person_name) values (3, 'Saman');
select * from Person;
