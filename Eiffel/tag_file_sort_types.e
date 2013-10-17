indexing

	description: "Constants describing defined tag file sort types."
	revision: "$Revision: 189 $"
	date: "$Date: 2002-08-26 03:16:52 +0000 (Mon, 26 Aug 2002) $"
	copyright: "Copyright 2002 Darren Hiebert and others"
	license: "Eiffel Forum License, version 1"

class TAG_FILE_SORT_TYPES

feature

	Sort_none: INTEGER is 0
			-- Tag file is not sorted

	Sort_case_sensitive: INTEGER is 1
			-- Tag file is sorted in case-sensitive manner

	Sort_case_insensitive: INTEGER is 2
			-- Tag file is sorted in case-insensitive manner, with lower-case
			-- folded onto upper case.

feature -- Status report

	valid_sort_type (sort: INTEGER): BOOLEAN is
			-- Is `sort' a valid tag file sort type?
		do
			Result := sort = Sort_none or
				sort = Sort_case_sensitive or
				sort = Sort_case_insensitive
		ensure
			definition: Result implies (sort = Sort_none or
				sort = Sort_case_sensitive or sort = Sort_case_insensitive)
		end

end
