#include "main.h"

/**
 * _cd - changes directory
 * Description: changes directory to specified file path
 *
 * @dir: directory
 * @env: environment pointer
 *
 * Return:
*/
int _cd_home(char *path, char **env)
{
	int status = 0;
	char *fpath, *oldwdir, *wdir = NULL, *ldir = "-";
	size_t dir_size = PATH_MAX;

	fpath = (path != NULL) ? _strdup(path) : _getenv("HOME", env);
	wdir = getcwd(wdir, dir_size);
	oldwdir = _getenv("OLDPWD", env);
	if (_strcmp(fpath, ldir) == 0)
	{
		free(fpath);
		fpath = NULL;
		fpath = oldwdir;
	}
	status = chdir(fpath);
	/* _setenv("OLDPWD", wdir, 1, env); */
	free(wdir);
	wdir = NULL;
	wdir = getcwd(wdir, dir_size);
	/* _setenv("PWD", wdir, 1, env); */

	if (status != 0)
		perror("cd");

	if (_strcmp(fpath, oldwdir) != 0)
	{
		free(oldwdir);
		oldwdir = NULL;
	}
	free(fpath);
	free(wdir);
	return(status);
}
