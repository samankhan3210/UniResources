1. Write a query to list the name, job name, department name, salary of the employees according to the department in ascending order.
SELECT E.FIRST_NAME|| ' ' || E.LAST_NAME AS "NAME",J.JOB_TITLE, D.DEPARTMENT_ID, D.DEPARTMENT_NAME, E.SALARY FROM EMPLOYEES E, JOBS J, DEPARTMENTS D WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND E.JOB_ID=J.JOB_ID ORDER BY DEPARTMENT_ID ASC;


1. Write a query to list the department where at least two employees are working.
SELECT D.DEPARTMENT_NAME FROM DEPARTMENTS D, EMPLOYEES E WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID GROUP BY D.DEPARTMENT_NAME HAVING COUNT(E.EMPLOYEE_ID)>=2;


1. Fetch all the records where salary of employee is less than the lower salary.
SELECT E.* FROM EMPLOYEES E, JOBS J WHERE E.JOB_ID=J.JOB_ID AND E.SALARY < J.MIN_SALARY;


1. Write a query to list the name, job name, annual salary, department id, department name and city who earn 60000 in a year or not working as an ANALYST.
SELECT E.FIRST_NAME|| ' ' || E.LAST_NAME AS "NAME",J.JOB_TITLE, E.SALARY*12 AS "ANNUAL_SALARY", D.DEPARTMENT_ID, D.DEPARTMENT_NAME, L.CITY 
FROM EMPLOYEES E, JOBS J, DEPARTMENTS D, LOCATIONS L WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND E.JOB_ID=J.JOB_ID AND D.LOCATION_ID=L.LOCATION_ID 
AND E.SALARY*12>=6000 OR J.JOB_TITLE NOT LIKE '%ANALYST%';


1. Write a query to print details of the employees who are also Managers.
SELECT E.* FROM EMPLOYEES E, JOBS J WHERE E.JOB_ID=J.JOB_ID AND J.JOB_TITLE LIKE '%Manager%'; 


