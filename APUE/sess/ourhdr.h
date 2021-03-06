apue/sess/orphan.c                                                                                     664     340      24         1661  5211774026   7456                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<signal.h>
#include	"ourhdr.h"

static void	sig_hup(int);
static void	pr_ids(char *);

int
main(void)
{
	char	c;
	pid_t	pid;

	pr_ids("parent");
	if ( (pid = fork()) < 0)
		err_sys("fork error");

	else if (pid > 0) {	/* parent */
		sleep(5);		/* sleep to let child stop itself */
		exit(0);		/* then parent exits */

	} else {			/* child */
		pr_ids("child");
		signal(SIGHUP, sig_hup);	/* establish signal handler */
		kill(getpid(), SIGTSTP);	/* stop ourself */
		pr_ids("child");	/* this prints only if we're continued */
		if (read(0, &c, 1) != 1)
			printf("read error from control terminal, errno = %d\n", errno);
		exit(0);
	}
}

static void
sig_hup(int signo)
{
	printf("SIGHUP received, pid = %d\n", getpid());
	return;
}

static void
pr_ids(char *name)
{
	printf("%s: pid = %d, ppid = %d, pgrp = %d\n",
			name, getpid(), getppid(), getpgrp());
	fflush(stdout);
}
		break;
		case 'n':		/* not interactive */
			interactive = 0;
			break;

		caapue/sess/tdaemon2.c                                                                                   664     340      24          375  5211774027   7662                                                                                                                                                                                                                                                                                                                                                                      #include	"ourhdr.h"

int
main(void)
{
	char	*ptr, buff[MAXLINE];

	daemon_init();

	close(0);
	close(1);
	close(2);

	ptr = getlogin();
	sprintf(buff, "login name: %s\n",
					(ptr == NULL) ? "(empty)" : ptr);
	write(3, buff, strlen(buff));
	exit(0);
}
ork error");

	else if (pid > 0) {	/* parent */
		sleep(5);		/* sleep to let child stop itself */
		exit(0);		/* then parent exits */

	} else {			/* child */
		pr_ids("child");
		signal(SIGHUP, sig_hup);	/* establish signal handler */
		kill(getpid(), SIGTSTapue/signals/                                                                                          775     340      24            0  5211773632   6417                                                                                                                                                                                                                                                                                                                                                                      apue/signals/Makefile                                                                                  664     340      24         1377  5211773625  10156                                                                                                                                                                                                                                                                                                                                                                      include ../Make.defines

PROGS =	abort.o child critical mask queue \
		raise.o read1 read2 readpart reenter \
		segv setops.o sigtstp sigusr \
		suspend1 suspend2 \
		system.o systest1 systest2 \
		trestart tsavedid tsiglist tsleep tsleep1 tsleep2 tsleep3 \
		ttellwait1 ttellwait2

all:	${PROGS}

systest1.o:
		${NOANSICOMPILE.c} systest1.c

# We want to link with our own version of system() for systest[12].
systest1: system.o systest1.o
		  $(LINK.c) -o $@ systest1.o system.o $(LDLIBS)

systest2: system.o systest2.o
	