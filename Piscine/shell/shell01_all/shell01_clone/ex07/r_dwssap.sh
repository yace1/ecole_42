cat /etc/passwd\
				| grep -v "#"\
				| rev \
				| cut -f -f7
