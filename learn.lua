-- this is single line comment
--[[
    This is block comment
    This is block comment
    This is block comment
    --]]

print("Hello world")

-- Only double type for numbers
num = 1024
num = 3.0
num = 3.14
num = 0xff -- hexadecimal
print(num)

globalVar = "All vars are global"
local localVar = "local prefix defines local var"

-- while
sum = 0
num = 1
while num <= 10 do
    sum = sum + num -- no +=
    num = num + 1   -- no ++
end
print("sum of 1~10:", sum)

-- if-else
if sum < 10 and num > 5 then
    print("impossible")
elseif sum > 10 and num ~= 10 then  -- ~= means !=
    print("also impossible")
else
    io.write("lalala "..globalVar)  -- .. is string concat
end

-- for
sum = 0
for i = 1, 100, 2 do    -- step as 2
    sum = sum + i
end

sum = 2
repeat
    sum = sum ^ 2
    print(sum)
until sum > 40

-- function
function fib(n)
    if n < 2 then return 1 end
    return fib(n - 2) + fib(n - 1)
end

function newCounter()
    local i = 0
    return function()   -- anonymous function
        i = i + 1
        return i
    end
end

c1 = newCounter()
print(c1())
print(c1())

function multiReturn()
    return 1, 2, "hello"
end

num1, num2, str = multiReturn()

-- Table (Like Dict/Map)
t = {name="caihua", age=31, male=True}
t.son="Henry"
t.age=32

for k, v in pairs(t) do
    print(k,v)
end

-- Array
arr = {1,2,3,4,5}
aarr = {"str", 3, function() print("item") end}
aarr[3]() -- index start from 1
print (#aarr)   -- array's length
