# it's not swap salary, it's swap sex
UPDATE salary set sex = char(ASCII('m') ^ ASCII('f') ^ ASCII(sex));
