1. For each department, retrieve the department no, the number of employees in the department and their average salary.
SELECT DEPARTMENT_ID, COUNT(DEPARTMENT_ID) AS "NUMBER OF EMPLOYEES", AVG(SALARY) AS "AVRAGE SALARY" FROM HR.EMPLOYEES GROUP BY DEPARTMENT_ID;

2. Write a Query to display the number of employees with the same job.
SELECT JOB_ID, COUNT(JOB_ID) AS "NUMBER OF EMPLOYEES" FROM HR.EMPLOYEES GROUP BY JOB_ID;

3. Write a Query to select Firstname and Hiredate of Employees Hired right after the joining of employee_ID no 110.
SELECT FIRST_NAME, HIRE_DATE FROM HR.EMPLOYEES WHERE HIRE_DATE > ALL(SELECT HIRE_DATE FROM HR.EMPLOYEES WHERE EMPLOYEE_ID=110);

4. Write a SQL query to select those departments where maximum salary is at least 15000.
SELECT DEPARTMENT_ID FROM HR.EMPLOYEES GROUP BY DEPARTMENT_ID HAVING MAX(SALARY)>=15000;

5. Write a query to display the employee number, name (first name and last name) and job title for all employees whose salary is smaller than any salary of those employees whose job title is IT_PROG.
SELECT EMPLOYEE_ID, FIRST_NAME || LAST_NAME AS "NAME", JOB_ID FROM HR.EMPLOYEES WHERE SALARY < ANY (SELECT SALARY FROM HR.EMPLOYEES WHERE JOB_ID='IT_PROG');

6. Write a query in SQL to display all the information of those employees who did not have any job in the past.
SELECT * FROM HR.EMPLOYEES WHERE EMPLOYEE_ID NOT IN (SELECT EMPLOYEE_ID FROM HR.JOB_HISTORY);


7. Display the manager number and the salary of the lowest paid employee of that manager. Exclude anyone whose manager is not known. Exclude any groups where the minimum salary is 2000. Sort the output is descending order of the salary.
SELECT MANAGER_ID, MIN(SALARY) AS "MIN SALARY" FROM HR.EMPLOYEES WHERE MANAGER_ID IS NOT NULL GROUP BY MANAGER_ID HAVING MIN(SALARY)>2000 ORDER BY MIN(SALARY) DESC;


8. Insert into employees_BKP as it should copy the record of the employee whose start date is '13-JAN-01' from job_History table.
CREATE TABLE EMPLOYEES_BKP AS SELECT *FROM HR.EMPLOYEES WHERE 1=2;
INSERT INTO EMPLOYEES_BKP SELECT * FROM HR.EMPLOYEES WHERE EMPLOYEE_ID IN (SELECT EMPLOYEE_ID FROM HR.JOB_HISTORY WHERE START_DATE='13-JAN-01');


9. Update salary of employees by 20% increment having minimu, salary of 6000.
UPDATE EMPLOYEES_BKP SET SALARY=SALARY+(0.2*SALARY) WHERE SALARY IN (SELECT SALARY FROM EMPLOYEES_BKP WHERE SALARY>=6000);  

10.Delete the record of employees from employees_BKP who are manager and belongs to the department ‘Finance’.
INSERT INTO EMPLOYEES_BKP SELECT * FROM HR.EMPLOYEES; 
DELETE EMPLOYEES_BKP WHERE EMPLOYEE_ID IN (SELECT DEPARTMENT_ID FROM HR.DEPARTMENTS WHERE DEPARTMENT_NAME='Finance');


11.For each department that has more than five employees, retrieve the department number and the number of its employees who are making more than $20,000.
SELECT DEPARTMENT_ID, COUNT(EMPLOYEE_ID) AS "NUMBER OF EMPLOYEES" FROM HR.EMPLOYEES WHERE SALARY IN (SELECT SALARY FROM HR.EMPLOYEES where SALARY>20000) GROUP BY DEPARTMENT_ID HAVING COUNT(EMPLOYEE_ID)>5;