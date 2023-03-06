1) Print an employee name (first letter capital) and job title (lower Case)
SELECT INITCAP(FIRST_NAME) || ' ' || INITCAP(LAST_NAME) AS "Name", LOWER(JOB_TITLE)AS "Job Title" FROM EMPLOYEES, JOBS; 

2) Display employee name and job title together, length of employee name and the numeric position of letter A in employee name, for all employees who are in sales.
Hint: For finding position you need to use string function “instr()”, this function worked
as INSTR(string1, string2)(s1:sreaching string, s2:string/char you’re searching for).
SELECT FIRST_NAME || ' ' || LAST_NAME || '-' || JOB_TITLE AS "Name - Job Title", LENGTH(FIRST_NAME || ' ' || LAST_NAME) AS "Lenght of Name",INSTR(FIRST_NAME || ' ' ||  LAST_NAME,'A') AS "Position of Letter 'A'" FROM EMPLOYEES,JOBS WHERE JOBS.JOB_TITLE LIKE '%Sales%';            


3) For all employees employed for more than 100 months, display the employee number, hire date, number of months employed, first Friday after hire date and last day of the month hired.
SELECT EMPLOYEE_ID, HIRE_DATE, MONTHS_BETWEEN(SYSDATE,hire_date) AS "Number of Months Employed", NEXT_DAY(HIRE_DATE, 'Friday') AS "First Friday After Hire Date", LAST_DAY(HIRE_DATE) AS "Last Day of the Month Hired" FROM EMPLOYEES WHERE MONTHS_BETWEEN(SYSDATE,HIRE_DATE)>100;


4) Comparing the hire dates for all employees who started in 2003, display the employee
number, hire date, and month started using the conversion and date functions.
SELECT EMPLOYEE_ID, HIRE_DATE, EXTRACT(MONTH FROM HIRE_DATE) AS "Month Started" FROM EMPLOYEES WHERE EXTRACT(YEAR FROM HIRE_DATE)=2003;

5) To display the employee number, the month number and year of hiring.
SELECT EMPLOYEE_ID, EXTRACT(MONTH FROM HIRE_DATE) AS "Hired Month", EXTRACT(YEAR FROM HIRE_DATE) AS "Hired Year" FROM EMPLOYEES;

6) To display the employee’s name and hire date for all employees. The hire date
appears as 16 September, 2021.
SELECT FIRST_NAME || ' ' || LAST_NAME AS "Name", TO_CHAR(HIRE_DATE, 'dd MONTH, YYYY') AS "Hired Date" FROM EMPLOYEES;

7) Display the salary of employee STEVEN with $ sign preceded.
SELECT TO_CHAR(SALARY,'$99999') AS "Salary" FROM EMPLOYEES WHERE FIRST_NAME='Steven';

8) Find the next ‘Monday’ considering today’s date as date.
SELECT  NEXT_DAY(SYSDATE,'MONDAY') from dual;

9) List all Employees who have an ‘A’ in their last names.
SELECT * FROM EMPLOYEES WHERE LAST_NAME LIKE '%a%';

10) Show all employees’ last three letters of first name
SELECT SUBSTR(FIRST_NAME,-3,LENGTH(FIRST_NAME)) FROM EMPLOYEES;

11) To display the employee number, name, salary of employee before and after 15% increment in the yearly salary. Name the calculated new salary as “Incremented Salary”. Do calculate the difference
between two salaries. Name the increased amount to be “Incremented Amount”.
SELECT PHONE_NUMBER,FIRST_NAME || ' ' || LAST_NAME AS "Name",SALARY,((SALARY*0.15)+SALARY) AS "INCREMENTED_SALARY",(((SALARY*0.15)+SALARY)-SALARY) AS "INCREMENTED AMOUNT" FROM EMPLOYEES;


12) List the name, hire date, and day of the week (labeled DAY) on which job was started. Order the result by day of week starting with Monday.
SELECT FIRST_NAME || ' ' || LAST_NAME AS "Name",HIRE_DATE, TO_CHAR(HIRE_DATE,'DAY') AS "DAY" FROM EMPLOYEES ORDER BY  TO_CHAR(HIRE_DATE-1,'d');


13) Display the department and manager id wise avg commission for all employees. Round the commission up to 1 decimals.
SELECT DEPARTMENT_ID, MANAGER_ID, ROUND(COMMISSION_PCT,1)AS "COMMISSION_PCT" FROM EMPLOYEES; 


PRACTICE TASKS:
1) Show last month and next month.
SELECT TO_CHAR(SYSDATE-30,'MONTH') AS "LAST MONTH", TO_CHAR(SYSDATE+30,'MONTH') AS "NEXT MONTH" FROM DUAL;

2) Show the last day of september, 2021
SELECT TO_CHAR(LAST_DAY('1-SEP-2021'), 'DAY') AS "LAST DAY OF SEP" FROM DUAL;

3) Show today's date, last day of this month, next Monday's date , next months, 1 st day.
SELECT TO_DATE(SYSDATE) as "TODAY" ,TO_CHAR(LAST_DAY(SYSDATE),'DAY') AS "LAST DAY", NEXT_DAY(SYSDATE,'MONDAY') AS "NEXT MONDAY",TO_CHAR(LAST_DAY(SYSDATE)+1,'DAY')  AS "NEXT MONTH'S 1ST DAY" FROM DUAL;

4) Show the number of days for this year to end.
SELECT ROUND((NEXT_DAY('30-DEC-21','FRI')-SYSDATE),0) AS "DAYS REMAINING" FROM DUAL;

5) Show the number of days left to end this month
SELECT LAST_DAY(SYSDATE)-SYSDATE AS "NUMBER OF DAYS LEFT" FROM DUAL;

6) Show the number of months between today and 1 Dec, 2021
SELECT ROUND(MONTHS_BETWEEN('1-DEC-2021',SYSDATE),1) AS "MONTHS B/W DEC SEP" FROM DUAL;

7) Show the number of months, each employee has worked from hire date.
SELECT FIRST_NAME || ' ' || LAST_NAME AS "NAME", ROUND(MONTHS_BETWEEN(SYSDATE,HIRE_DATE),1) AS "MONTHS WORKED" FROM EMPLOYEES;

8) Show the new year considering the date 16-Feb-2021.
SELECT EXTRACT(YEAR FROM TO_DATE('16-Feb-2021'))+1 AS "NEXT YEAR" FROM DUAL;

9) Show the new month, considering 16 sept, 2021.
SELECT TO_CHAR(LAST_DAY('16-SEP-2021')+1,'MONTH') AS "NEW MONTH" FROM DUAL;

10) Show the new month, considering 12 sept, 2021.
SELECT TO_CHAR(LAST_DAY('12-SEP-2021')+1,'MONTH') AS "NEW MONTH" FROM DUAL;

11) Show tomorrows date as Tomorrow
SELECT TO_DATE(SYSDATE)+1 as "TOMORROW" FROM DUAL;

12) Show the next month’s name.
SELECT TO_CHAR(LAST_DAY(SYSDATE)+1,'MONTH') AS "NEW MONTH" FROM DUAL;

13) select round(sysdAte, 'YEAR') AS "Next Year" from dual;
SELECT ROUND(SYSDATE,'YEAR') AS "NEXT YEAR" FROM DUAL;

14) Show the time for five minutes from now.
SELECT ADDTIME(CURRENT_TIMESTAMP, "0:5:0") AS "TIME" FROM DUAL; --this gives no error on online editor but doesnt work here

15) Show the first name, hiredate in format: SEPTEMBER 12, 2021, SALARY IN $99999.99 for first five
rows.
SELECT FIRST_NAME,TO_CHAR(HIRE_DATE,'dd MONTH,YYYY') AS "HIRE DATE", TO_CHAR(SALARY,'$999999') AS "SALARY" FROM EMPLOYEES WHERE ROWNUM <= 5;

16) Show odd rows from table having first anme, emp id, rownum from employees table.
SELECT * FROM (SELECT FIRST_NAME,EMPLOYEE_ID, ROWNUM AS "ROW#" FROM EMPLOYEES) EMPLOYEES  WHERE MOD(ROW#,2)!=0; 