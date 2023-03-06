--1. Create a new user using SQL command Line and grant privileges. We are using this user to create our own database with related tables, which we are working on in lab#03.
--Screenshot attached

--2. Create table Jobs and job_History (ignore foreign keys relations) same fields as given in HR schema in which job_ID is considered as primary key in jobs table.
CREATE TABLE JOBS(JOB_ID VARCHAR2 (10) PRIMARY KEY, JOB_TITLE VARCHAR2 (35) NOT NULL, MIN_SALARY NUMBER (6),MAX_SALARY NUMBER (6));
CREATE TABLE JOB_HISTORY(START_DATE DATE NOT NULL, END_DATE DATE NOT NULL, DEPARTMENT_ID NUMBER (4), CONSTRAINT JHIST CHECK(START_DATE < END_DATE AND END_DATE > START_DATE));


--3. Change the data type of ‘job_ID’ from character to numeric in Jobs table.(Like IT_Prog->101).
ALTER TABLE JOBS MODIFY (JOB_ID NUMBER (6));


--4. Write a SQL statement to add job_id column in job_history table as foreign key referencing to the primary key job_id of jobs table.
ALTER TABLE JOB_HISTORY ADD (JOB_ID NUMBER (6) NOT NULL);
ALTER TABLE JOB_HISTORY ADD CONSTRAINT FK_CT FOREIGN KEY (JOB_ID) REFERENCES JOBS(JOB_ID);


--5. Insert a new row in jobs table having all the attributes and the job_ID should update in job_History table as welL.
INSERT INTO JOBS VALUES (001, 'MANAGER', 35000, 55000);
INSERT INTO JOB_HISTORY VALUES ('1-JAN-2021', '12-DEC-2021', 123, 001);


--6. Add Column Job_Nature in Jobs table.
ALTER TABLE JOBS ADD (JOB_NATURE VARCHAR2 (30) DEFAULT NULL);


--7. Create replica of employee table.
CREATE TABLE EMP_REP AS SELECT * FROM HR.EMPLOYEES;


--8. Write a SQL statement to add employee_id column in job_history table as foreign key referencing to the primary key employee_id of employees table.
DELETE FROM JOB_HISTORY;  --HAD TO DLETE THE OLD DATA IN JOB_HISTORY TABLE TO ADD  THE FOREIGN KEY 
ALTER TABLE JOB_HISTORY ADD (EMPLOYEE_ID NUMBER (6));
ALTER TABLE EMP_REP ADD CONSTRAINT PK_CT UNIQUE (EMPLOYEE_ID);
ALTER TABLE JOB_HISTORY ADD CONSTRAINT FK_2 FOREIGN KEY (EMPLOYEE_ID) REFERENCES EMP_REP(EMPLOYEE_ID);


--9. Drop column Job_Nature.
ALTER TABLE JOBS DROP (JOB_NATURE); 

--10. ALTER table EMPLOYEE created in question 5 and apply the constraint CHECK on First_Name attribute such that ENAME should always be inserted in capital letters.
DELETE FROM EMP_REP; --HAD TO DLETE THE OLD DATA IN EMPLOYEE TABLE TO ADD THIS CHECK CONSTRAINT 
ALTER TABLE EMP_REP ADD CONSTRAINT CT_2 CHECK(FIRST_NAME=UPPER(FIRST_NAME));


--11. ALTER table EMPLOYEE created in question 5 and apply the constraint on SALary attribute such that no two salaries of the employees should be similar.(Hint Unique)
ALTER TABLE EMP_REP ADD CONSTRAINT UK_CT UNIQUE (SALARY);


--12. ALTER table Employee created in question 5 and apply constraint on Phone_No such that Phone_No should not be entered empty (Hint modify).
ALTER TABLE EMP_REP MODIFY (PHONE_NUMBER NOT NULL); 

--13. Write a SQL statement to insert one row into the table employees.
INSERT INTO EMP_REP (EMPLOYEE_ID ,FIRST_NAME ,LAST_NAME ,EMAIL ,PHONE_NUMBER ,HIRE_DATE ,JOB_ID ,SALARY ,COMMISSION_PCT ,
MANAGER_ID ,DEPARTMENT_ID) VALUES(0011, 'SAMAN', 'KHAN', 'K190354@','12345','22-SEP-21','10',10000.00,0.10,33,44); 


--14. Write a SQL statement to change the salary of employee to 8000 who’s ID is 105, if the existing salary is less than 1+000.
UPDATE EMP_REP SET SALARY=8000 WHERE EMPLOYEE_ID=105 AND SALARY<1000; 

--15. Write a SQL statement to add a primary key for a combination of columns employee_id and job_id in employees table, give the reason why this command is showing error.
ALTER TABLE EMP_REP ADD PRIMARY KEY(EMPLOYEE_ID, JOB_ID); --THERE CANNOT BE MORE THAN ON PRIMARY KEY IN A TABLE AND IN THIS TABLE EMPLOYEE_ID IS ALREADY A PRIAMRY KEY.

--16. Write a SQL statement to add an index named indx_job_id on job_id column in the table job_history.
CREATE UNIQUE INDEX indx_job_id ON JOB_HISTORY (JOB_ID);


--17. Write a SQL statement to remove employees table.
DROP TABLE JOB_HISTORY; --TO REMOVE EMPLOYEES TABLE WE NEED TO REMOVE JOB_HISTORY TABLE FIRST BECAUSE OF THE FOREIGN KEY OF EMPLOYEE_ID IN JOB_HISTORY
DROP TABLE EMP_REP;