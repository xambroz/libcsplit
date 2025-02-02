/*
 * Library narrow_split_string type test program
 *
 * Copyright (C) 2008-2023, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "csplit_test_libcerror.h"
#include "csplit_test_libcsplit.h"
#include "csplit_test_macros.h"
#include "csplit_test_memory.h"
#include "csplit_test_unused.h"

#include "../libcsplit/libcsplit_narrow_split_string.h"

#if defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT )

/* Tests the libcsplit_narrow_split_string_initialize function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_initialize(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	int result                                    = 0;

#if defined( HAVE_CSPLIT_TEST_MEMORY )
	int number_of_malloc_fail_tests                      = 4;
	int number_of_memcpy_fail_tests                      = 1;
	int number_of_memset_fail_tests                      = 3;
	int test_number                                      = 0;
#endif

	/* Test libcsplit_narrow_split_string_initialize
	 */
	result = libcsplit_narrow_split_string_initialize(
	          &split_string,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcsplit_narrow_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_initialize(
	          NULL,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	split_string = (libcsplit_narrow_split_string_t *) 0x12345678UL;

	result = libcsplit_narrow_split_string_initialize(
	          &split_string,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	split_string = NULL;

	result = libcsplit_narrow_split_string_initialize(
	          &split_string,
	          "Test",
	          4,
	          -1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CSPLIT_TEST_MEMORY )
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcsplit_narrow_split_string_initialize with malloc failing
		 */
		csplit_test_malloc_attempts_before_fail = test_number;

		result = libcsplit_narrow_split_string_initialize(
		          &split_string,
		          "Test",
		          4,
		          1,
		          &error );

		if( csplit_test_malloc_attempts_before_fail != -1 )
		{
			csplit_test_malloc_attempts_before_fail = -1;
		}
		else
		{
			CSPLIT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CSPLIT_TEST_ASSERT_IS_NULL(
			 "split_string",
			 split_string );

			CSPLIT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memcpy_fail_tests;
	     test_number++ )
	{
		/* Test libcsplit_narrow_split_string_initialize with memcpy failing
		 */
		csplit_test_memcpy_attempts_before_fail = test_number;

		result = libcsplit_narrow_split_string_initialize(
		          &split_string,
		          "Test",
		          4,
		          1,
		          &error );

		if( csplit_test_memcpy_attempts_before_fail != -1 )
		{
			csplit_test_memcpy_attempts_before_fail = -1;
		}
		else
		{
			CSPLIT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CSPLIT_TEST_ASSERT_IS_NULL(
			 "split_string",
			 split_string );

			CSPLIT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libcsplit_narrow_split_string_initialize with memset failing
		 */
		csplit_test_memset_attempts_before_fail = test_number;

		result = libcsplit_narrow_split_string_initialize(
		          &split_string,
		          "Test",
		          4,
		          1,
		          &error );

		if( csplit_test_memset_attempts_before_fail != -1 )
		{
			csplit_test_memset_attempts_before_fail = -1;
		}
		else
		{
			CSPLIT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CSPLIT_TEST_ASSERT_IS_NULL(
			 "split_string",
			 split_string );

			CSPLIT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CSPLIT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libcsplit_narrow_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT ) */

/* Tests the libcsplit_narrow_split_string_free function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_free(
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcsplit_narrow_split_string_get_string function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_get_string(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	char *string                                  = NULL;
	size_t string_size                            = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcsplit_narrow_string_split(
	          "Test 1 2 3 4 5",
	          15,
	          ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcsplit_narrow_split_string_get_string(
	          split_string,
	          &string,
	          &string_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	CSPLIT_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 15 );

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_get_string(
	          NULL,
	          &string,
	          &string_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_string(
	          split_string,
	          NULL,
	          &string_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_string(
	          split_string,
	          &string,
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcsplit_narrow_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libcsplit_narrow_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcsplit_narrow_split_string_get_number_of_segments function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_get_number_of_segments(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	int number_of_segments                        = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcsplit_narrow_string_split(
	          "Test 1 2 3 4 5",
	          15,
	          ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcsplit_narrow_split_string_get_number_of_segments(
	          split_string,
	          &number_of_segments,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "number_of_segments",
	 number_of_segments,
	 6 );

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_get_number_of_segments(
	          NULL,
	          &number_of_segments,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_number_of_segments(
	          split_string,
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcsplit_narrow_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libcsplit_narrow_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcsplit_narrow_split_string_get_segment_by_index function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_get_segment_by_index(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	char *string_segment                          = NULL;
	size_t string_segment_size                    = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcsplit_narrow_string_split(
	          "Test 1 2 3 4 5",
	          15,
	          ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcsplit_narrow_split_string_get_segment_by_index(
	          split_string,
	          0,
	          &string_segment,
	          &string_segment_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "string_segment",
	 string_segment );

	CSPLIT_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 5 );

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_get_segment_by_index(
	          NULL,
	          0,
	          &string_segment,
	          &string_segment_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_segment_by_index(
	          split_string,
	          -1,
	          &string_segment,
	          &string_segment_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_segment_by_index(
	          split_string,
	          0,
	          NULL,
	          &string_segment_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_get_segment_by_index(
	          split_string,
	          0,
	          &string_segment,
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcsplit_narrow_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libcsplit_narrow_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT )

/* Tests the libcsplit_narrow_split_string_set_segment_by_index function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_split_string_set_segment_by_index(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	char *string                                  = NULL;
	size_t string_size                            = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcsplit_narrow_split_string_initialize(
	          &split_string,
	          "TestTest",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcsplit_narrow_split_string_get_string(
	          split_string,
	          &string,
	          &string_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	CSPLIT_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	/* Test regular cases
	 */
	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          string,
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcsplit_narrow_split_string_set_segment_by_index(
	          NULL,
	          0,
	          string,
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          -1,
	          string,
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          NULL,
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          (char *)( (intptr_t) string - ( 1 * sizeof( char ) ) ),
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          (char *)( (intptr_t) string + ( 2 * sizeof( char ) ) ),
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          (char *)( (intptr_t) string + ( 4 * sizeof( char ) ) ),
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          string,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_narrow_split_string_set_segment_by_index(
	          split_string,
	          0,
	          &( string[ 4 ] ),
	          4,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcsplit_narrow_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libcsplit_narrow_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CSPLIT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CSPLIT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CSPLIT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CSPLIT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CSPLIT_TEST_UNREFERENCED_PARAMETER( argc )
	CSPLIT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT )

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_initialize",
	 csplit_test_narrow_split_string_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT ) */

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_free",
	 csplit_test_narrow_split_string_free );

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_get_string",
	 csplit_test_narrow_split_string_get_string );

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_get_number_of_segments",
	 csplit_test_narrow_split_string_get_number_of_segments );

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_get_segment_by_index",
	 csplit_test_narrow_split_string_get_segment_by_index );

#if defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT )

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_split_string_set_segment_by_index",
	 csplit_test_narrow_split_string_set_segment_by_index );

#endif /* defined( __GNUC__ ) && !defined( LIBCSPLIT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

