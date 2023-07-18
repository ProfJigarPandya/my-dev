mail -s "Learning here document" jpandya@localhost.localdomain <<HEREDOC
hi,
You may type anything which was suppose to be entered by keyboard here
in heredoc.
HEREDOC
echo "Today is `date`"
