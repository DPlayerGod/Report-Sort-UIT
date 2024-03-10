@echo off

for %%d in (*.inp) do (
   echo processing... %%~nd
   MergeSort.exe < %%d > %%~nd.out
)

