1. List department number, Department name for all the departments in which there are no employees in the department.
SELECT DEPARTMENT_ID FROM DEPARTMENTS MINUS SELECT DEPARTMENT_ID FROM EMPLOYEES;

1. Display employee name, salary, department name where all employees has matching department as well as employee does not have any departments.
SELECT E1.FIRST_NAME|| ' ' || E1.LAST_NAME AS "NAME", E1.SALARY, E1.DEPARTMENT_ID FROM EMPLOYEES E1, EMPLOYEES E2 WHERE E2.DEPARTMENT_ID=E1.DEPARTMENT_ID AND E2.EMPLOYEE_ID=E1.EMPLOYEE_ID OR E1.DEPARTMENT_ID=NULL;

1. Display name, job ID, department name, street address and city of the employee in which there is no state province.
SELECT E.FIRST_NAME|| ' ' || E.LAST_NAME AS "NAME", E.JOB_ID, D.DEPARTMENT_NAME, L.STREET_ADDRESS, L.CITY FROM EMPLOYEES E, DEPARTMENTS D, LOCATIONS L WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND D.LOCATION_ID=L.LOCATION_ID AND L.STATE_PROVINCE IS NULL;

1. Write an SQL query to show records from one table that another table does not have.
SELECT * FROM TABLE_1 T1 MINUS SELECT * FROM TABLE_2 T2;        --PATTERN
SELECT DEPARTMENT_ID FROM DEPARTMENTS MINUS SELECT DEPARTMENT_ID FROM EMPLOYEES;  --EXAMPLE

1. Display all employees who belong to country US but not belongs to state province Washington.
SELECT E.* FROM EMPLOYEES E, DEPARTMENTS D, LOCATIONS L WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND D.LOCATION_ID=L.LOCATION_ID AND L.COUNTRY_ID='US' AND L.STATE_PROVINCE!='Washington';
