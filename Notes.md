**WAL steps**
transaction start  
→ modify data in memory  
→ write log record  
→ write commit record 
→ flush log to disk(also called fsync log)  
→ transaction successful  
→ data page written later (any time)  

<u>if transaction has commit record=REDO</u>* 
<u>If transaction does not have commmit record = UNDO</u>

**Case A -- Crash After commit**  


transaction start
→ modify data in memory(new value 10 earlier it was 50)  
→ write log record(log is updated with new value 10)  
→ commit(commit in log)  
→ flush log to disk  
########Crash Happen#########(still we have value 50 in data page-since commit have transaction record hence undo happen)


**Case B -- Crash Before commit**  


→ modify data in memory(new value 10 earlier it was 50)  
→ write log record(log is updated with new value 10)  
#####Crash happen######(log sees new value 10 but disk sees old value 50 since transaction does not have cmmit record hence it should be UNDO)
