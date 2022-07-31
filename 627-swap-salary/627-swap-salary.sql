# Write your MySQL query statement below
update salary SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;