#include "main.h"

/**
 * free_null - frees and nulls a dynamically allocated string
 * Description: function takes a dynamically allocated string
 * and free's the string then sets it to null. It is the responsibility
 * of the caller to ensure argument passed is dynamically allocated
 * using malloc, realloc or calloc, otherwise will get invalid free error
 *
 * @dstr: dynamically allocated string
 *
 * Return: 0 on success, -1 on error
 */
int free_null(char *dstr)
{
	if (dstr == NULL)
		return (-1);
	free(dstr);
	dstr = NULL;
	return (0);
}

/**
 * _cdir - changes directory to specified file path
 * Description: takes a filepath and changes cwd to
 * specified path, updates pwd & oldpwd env variables
 * in process
 *
 * @filepath: string directory name
 * @env: pointer to env variables linked list
 *
 * Return: int, -1 on error, 0 on success
 */
int _cdir(char *filepath, enode *env)
{
	char *cwd = NULL, *opwd = NULL, *nwd = NULL, *fpath, *_resolvedpath = NULL;
	int ret = 0;

	if (filepath == NULL || env == NULL)
		return (-1);

	cwd = getcwd(cwd, PATH_MAX);
	opwd = _getenv("OLDPWD", env);
	_resolvedpath = realpath(filepath, _resolvedpath);

	fpath = filepath;
	if (_strcmp(filepath, "-") == 0)
		fpath = opwd;
	if (_strcmp(filepath, "..") == 0 || _strcmp(filepath, ".") == 0)
		fpath = _resolvedpath;

	ret = chdir(fpath);
	if (ret == 0)
	{
		_setenv("OLDPWD", cwd, 1, env);
		nwd = getcwd(nwd, PATH_MAX);
		_setenv("PWD", nwd, 1, env);
	}
	free_null(opwd);
	free_null(cwd);
	free_null(_resolvedpath);
	free_null(nwd);
	return (ret);
}
