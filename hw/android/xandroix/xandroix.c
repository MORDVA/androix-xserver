/*

Copyright 2010 Timothy Meade

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "../android.h"

#include <unistd.h>
#include <stdio.h>

static pthread_mutex_t miEventQueueMutex = PTHREAD_MUTEX_INITIALIZER;

extern int dix_main(int argc, char *argv[], char *envp[]);

int main(int argc, char *argv[], char *envp[])
{
    Android = (AndroidVars *)calloc(sizeof(AndroidVars), 1);
    Android->miEventQueueMutex = &miEventQueueMutex;

	LOG("[xandroix main] starting dix_main in main thread\n");
	dix_main(argc, argv, envp);
	LOG("[xandroix main] dix_main exited in main thread\n");
}
