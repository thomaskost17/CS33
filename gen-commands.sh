gnoring paging and asked for pressing c to continue
echo "set pagination off"

# Set breakpoint
echo "break Ftimes"

# Turn color characters like [34 off in our output
echo "set style enabled off"

# Start running the program
echo "run -Q -batch -eval '(print (* 1250284240 -1844255039))'"

# Output GDB commands to file 
echo "set logging on"

# Get the output with opcodes
echo "set disassemble-next-line on"

# Stepi 250 times
for i in {1..218}
do
	    echo "stepi"
    done

    #Skip this printf
    echo "nexti"

    # Stepi 24 times
    for i in {1..22}
    do
	        echo "stepi"
	done
	echo "nexti"

	# Manually edit this file to generate the exact stepi and nexti you need
	# to skip over some unnecessary functions

	# Quit without asking
	echo "set confirm off"
	echo "quit"
