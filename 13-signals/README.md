Sending and Handling Signals in C (kill, signal, sigaction) (Jacob Sorber)
https://www.youtube.com/watch?v=83M5-NPDeWs




Windows emulates a small set of POSIX signals
Using signal() in Windows C++

Windows does not support:
    kill(pid, signal) in the Unix sense
    Custom signal numbers or handlers beyond the standard set
    Process group signals (e.g., SIGSTOP, SIGKILL)

✅ Windows Equivalents
Unix Signal	Windows Equivalent
SIGKILL	TerminateProcess()
SIGINT	Ctrl+C event via GenerateConsoleCtrlEvent()
SIGSEGV	Structured Exception Handling (SEH)
SIGTERM	ExitProcess(), TerminateProcess()

🛠 For Advanced Cases: Use SEH
Windows uses Structured Exception Handling (SEH) instead of signals for faults like segmentation faults or illegal instructions.
📌 There’s no single name like “Windows Signals,” but collectively:

🟩 You can think of “Structured Exception Handling + Console Control Events + Process Control APIs” as Windows' answer to signals.