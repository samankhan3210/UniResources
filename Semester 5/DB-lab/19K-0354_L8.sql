/*1. Create a PL/SQL block that computes and prints the bonus amount for a given Employee
based on the employee’s salary. Accept the employee number as user input with a
SQL*Plus substitution Variable.
a. If the employee’s salary is less than 1,000, set the bonus amount for the
b. Employee to 10% of the salary.
c. If the employee’s salary is between 1,000 and 1,500, set the bonus amount for the
employee to 15% of the salary.
d. If the employee’s salary exceeds 1,500, set the bonus amount for the employee to
20% of the salary.
e. If the employee’s salary is NULL, set the bonus amount for the employee to 0. */
Set SERVEROUTPUT ON;
accept emp_id number prompt 'Enter employee id : '
declare 
        sal number;
        emp_id number := &emp_id;
        bonus number := 0;
begin
         select salary into sal from employees where employee_id=emp_id;
         if (sal < 1000) then
            bonus := (sal * 0.1);
         elsif (sal >= 1000 and sal <= 1500) then
            bonus :=(sal * 0.15);
         elsif (sal > 1500) then
            bonus := (sal * 0.2);        
         else 
            bonus := 0;
         end if;
         dbms_output.put_line('Salary : '  ||  sal); 
         dbms_output.put_line('Bonus : '  ||  bonus); 
end;
  
    
/*2. Write a pl/sql block in sql that ask a user for employee id than it checks its commission if
commission is null than it updates salary of that employee by adding commission into
salary.*/
Set SERVEROUTPUT ON;
accept emp_id number prompt 'Enter employee id : '
declare 
        emp_id employees.EMPLOYEE_ID%type;
        comm employees.COMMISSION_PCT%type;
begin
         emp_id := &emp_id;
         select commission_pct into comm from employees where employee_id=emp_id;
         if (comm is NULL) then
            update employees set salary=commission_pct+salary where employee_id=emp_id;                  
            dbms_output.put_line('Salary updated'); 
         else 
            dbms_output.put_line('Commission is not null'); 
         end if;
end;
    
--3. Write a PL/SQL block to obtain the department name of the employee who works for deptno 30
Set SERVEROUTPUT ON;
declare 
        dept_id employees.department_id%type := 30;
        dpt_name departments.department_name%type;
begin
         select department_name into dpt_name from departments where department_id=dept_id;
         dbms_output.put_line(' Department Name : ' || dpt_name); 
end;


--4. Write a PL /SQL block to find the nature of job of the employee whose deptno is 20(to be passed as an argument)
create or replace procedure findJobNature(dept_id in number)
is  
nature departments.department_name%type;
begin 
    for var in (select j.job_title into nature from jobs j, employees e where e.department_id=dept_id and j.job_id=e.job_id)
    loop
        dbms_output.put_line(' Job Nature : ' || var.job_title); 
    end loop;
end;
exec findJobNature(20);


--5. Write a PL /SQL block to find the salary of the employee who is working in the deptno 20(to be passed as an argument).
create or replace procedure findSalary(dept_id in number)
is  sal employees.salary%type;
begin 
    for var in (select salary into sal from employees where department_id=dept_id)
    loop
        dbms_output.put_line('Salary : ' || var.salary); 
    end loop;
end;
exec findSalary(20);


--6. Write a PL/SQL block to update the salary of the employee with a 10% increase whose empno is to be passed as an argument for the procedure
set serveroutput on;
create or replace procedure incrementSal(emp_id number)
is sal employees.salary%type;
begin
    select salary into sal from employees where employee_id=emp_id;                      
    dbms_output.put_line('Old Salary = ' ||sal); 
    update employees set salary=((salary*0.1))+salary where employee_id=emp_id; 
    select salary into sal from employees where employee_id=emp_id;                      
    dbms_output.put_line('New Salary = ' ||sal); 
    dbms_output.put_line('Salary Updated for employee with employee id = ' ||emp_id); 
end;

exec incrementSal(103);


--7. Write a procedure to add an amount of Rs.1000 for the employees whose salaries is greater than 5000 and who belongs to the deptno passed as an argument.
set serveroutput on;
create or replace procedure EditSal(dept_id number)
is 
begin
    update employees set salary=(1000+salary) where department_id=dept_id and salary>5000;  
    dbms_output.put_line('Salary Updated for employee with salary greater than 5000 and department id = ' ||dept_id); 
end;

exec EditSal(30);


--8. Create views for following purposes:-
--a. Display each designation and number of employees with that particular designation.
CREATE or REPLACE VIEW EMP_Des AS SELECT j.job_title as "Designation", count(e.employee_id) as "Number of Employees" FROM EMPLOYEES e, jobs j where e.job_id=j.job_id group by j.job_title;
select * from emp_des;

--b. The organization wants to display only the details like empno, empname , deptno ,deptname of all the employee except king.
CREATE or REPLACE VIEW org_view AS SELECT e.employee_id  as "Employee Number", (e.first_name || ' ' || e.last_name) as "Employee Name", d.department_id as "Departmnent Number",
d.department_name as "Departmnent Name" FROM EMPLOYEES e, Departments d where e.department_id=d.department_id and (lower(e.first_name) || ' ' || lower(e.last_name)) not like '%king%';
select * from org_view;

--c. The organization wants to display only the details empno, empname, deptno, deptname of the employees.
CREATE or REPLACE VIEW org_info AS SELECT e.employee_id  as "Employee Number", (e.first_name || ' ' || e.last_name) as "Employee Name", d.department_id as "Departmnent Number",
d.department_name as "Departmnent Name" FROM EMPLOYEES e, Departments d where e.department_id=d.department_id;
select * from org_info;


--9. Write a PL/SQL code that takes two inputs from user, add them and store the sum in new variable and show the output.
Set SERVEROUTPUT ON;
accept num1 number prompt 'Enter the first number : '
accept num2 number prompt 'Enter the second number : '
declare 
        num1 number;
        num2 number;
        num number;
begin
         num1 := &num1;
         num2 := &num2;
         num := num1+num2;
         dbms_output.put_line('Sum = '||num);  
end;


--10. Write a PL/SQL code that takes two inputs, lower boundary and upper boundary, then print the sum of all the numbers between the boundaries INCLUSIVE.
Set SERVEROUTPUT ON;
accept num1 number prompt 'Enter the lower boundary : '
accept num2 number prompt 'Enter the upper boundary : '
declare 
        num1 number;
        num2 number;
        num number := 0;
        co number := 0;
begin
         num1 := &num1;
         num2 := &num2;
         for co in num1 .. num2
         loop
            num := num+co;
         end loop;
         dbms_output.put_line('Sum = '||num);  
end;

--11. Write a PL/SQL code to retrieve the employee name, hiredate, and the department name in which he works, whose number is input by the user.
Set SERVEROUTPUT ON;
accept emp number prompt 'Enter the employee id : '
declare 
        emp_name employees.first_name%type;
        emp_date employees.hire_date%type;
        dept departments.department_name%type;
begin
         select (e.first_name || ' ' || e.last_name), e.hire_date, d.department_name into emp_name, emp_date, dept from 
         employees e, departments d where e.employee_id=&emp and e.department_id=d.department_id;
         dbms_output.put_line('Employee Name = '||emp_name);  
         dbms_output.put_line('Employee Hire Date = '||emp_date);  
         dbms_output.put_line('Department Name = '||dept);  
end;


--12. Write a PL/SQL code to check whether the given number is palindrome or not.
Set SERVEROUTPUT ON;
accept num number prompt 'Enter the number : '
declare 
    num number := &num;
    var number;
    var1 number := 0;
    var2 number;
begin
    var := num;
    while(var > 0)
    loop
        var2 := mod(var,10);
        var1 := (var1*10) + var2;
        var := trunc(var/10);
    end loop;
    if (var1 = num) then
        dbms_output.put_line('Number is palindrome');
    else
        dbms_output.put_line('Number is palindrome');
    end if;
end;


--13. Write a PL/SQL code that takes all the required inputs from the user for the Employee table and then insert it into the Employee and Department table in the database.
set serveroutput on;
declare
    employee_id     employees.employee_id%type := &employee_id;
    first_name      employees.first_name%type := &first_name;
    last_name       employees.last_name%type := &last_name;
    email           employees.email%type := &email;
    phone_number    employees.phone_number%type := &phone_number;
    hire_date       employees.hire_date%type := &hire_date;
    job_id          employees.job_id%type := &job_id;
    salary          employees.salary%type := &salary;
    commission_pct  employees.commission%type := &commission_pct;
    manager_id      employees.manager_id%type := &manager_id;
    department_id   employees.department_id%type := &department_id;
    flag            boolean := false;
begin 
    for co in (select d.department_id from departments d)
    loop
        if (department_id = co.department_id) then
            flag := true;
        end if;
    end loop;
    if (flag=false) then
        insert into departments values(department_id,'ABC');
    end if; 
    insert into employees values(employee_id, first_name,last_name, email,phone_number,hire_date,job_id,salary, commission_pct,manager_id,department_id);
end;


--14. Write a PL/SQL code to find the first employee who has a salary over $2500 and is higher in the chain of command than employee 7499. Note: For chain, use of LOOP is necessary.
set serveroutput on;
declare
   salary       employees.salary%type;
   manager_id   employees.manager_id%type;
   e_id         employees.employee_id%type := &e_id;
begin
   select e.manager_id into manager_id from employees e where e.employee_id=e_id;
   while salary <= 2500 
   loop
      select e.salary, e.manager_id into salary, manager_id from hr.employees e where  employee_id= manager_id;
   end loop;
   if(salary>2500) then 
       dbms_output.put_line('Salary: ' ||salary);
    else
        dbms_output.put_line('No match found');
    end if;
end;


--15. Write a PL/SQL code to print the sum of first 100 numbers.
set serveroutput on;
declare 
    s integer := 0;
    i integer := 100;
begin
    while (i > 0)
    loop
        s := s + i;
        i := i - 1;
    end loop;
    dbms_output.put_line('Sum of first 100 numbers = '|| s);
end;