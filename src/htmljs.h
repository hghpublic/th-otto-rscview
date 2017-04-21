static char const html_javascript_code[] =
	"\"use strict;\"\n"

	"function showPopup (id) {\n"
	"  var a = document.getElementById(id + '_content');\n"
	"  if (a) {\n"
	"    if (a.style.display == 'none' || a.style.display == '') {\n"
	"      a.style.display = 'block';\n"
	"    } else {\n"
	"      a.style.display = 'none';\n"
	"    }\n"
	"  }\n"
	"}\n"
	"function hidePopup (id) {\n"
	"  var a = document.getElementById(id + '_content');\n"
	"  if (a)\n"
	"    a.style.display = 'none';\n"
	"}\n"

	"function hideInfo () {\n"
	"  var id = 'rsc_info';\n"
	"  var a = document.getElementById(id + '_content');\n"
	"  if (a)\n"
	"    a.style.display = 'none';\n"
	"}\n"

	"function showInfo () {\n"
	"  var id = 'rsc_info';\n"
	"  var a = document.getElementById(id + '_content');\n"
	"  if (a) {\n"
	"    if (a.style.display == 'none' || a.style.display == '') {\n"
	"      a.style.display = 'inline-block';\n"
	"    } else {\n"
	"      a.style.display = 'none';\n"
	"    }\n"
	"  }\n"
	"}\n"

	"function getQueryVariable(variable)\n"
	"{\n"
	"  var query = window.location.search.substring(1);\n"
	"  var vars = query.split('&');\n"
	"  for (var i = 0; i < vars.length; i++) {\n"
	"    var pair = vars[i].split('=');\n"
	"    if (decodeURIComponent(pair[0]) == variable) {\n"
	"      return decodeURIComponent(pair[1]);\n"
	"    }\n"
	"  }\n"
	"  return '';\n"
	"}\n"
	"var lang;\n"
	"var languages = ['en', 'de'];\n"

	"function getSupportedLanguage(l)\n"
	"{\n"
	"  for (var j = 0; j < languages.length; j++) {\n"
	"    if (languages[j] == l) return l;\n"
	"  }\n"
	"  return '';\n"
	"}\n"

	"function getAcceptLanguage()\n"
	"{\n"
	"  if (window.navigator.languages) {\n"
	"    for (var i = 0; i < window.navigator.languages.length; i++) {\n"
	"      var l = window.navigator.languages[i].split('-')[0].split('_')[0];\n"
	"      l = getSupportedLanguage(l);\n"
	"      if (l != '') return l;\n"
	"    }\n"
	"  }\n"
	"  return '';\n"
	"}\n"

	"function getLanguage()\n"
	"{\n"
	"  var l = getQueryVariable('lang').split('-')[0].split('_')[0];\n"
	"  if (l == '') {\n"
	"    l = getAcceptLanguage();\n"
	"  }\n"
	"  l = getSupportedLanguage(l);\n"
	"  if (l == '')\n"
	"    l = getSupportedLanguage(navigator.language);\n"
	"  if (l == '')\n"
	"    l = 'en';\n"
	"  lang = l;\n"
	"  var html = document.getElementsByTagName('html')[0];\n"
	"  html.setAttribute('lang', lang);\n"
	"  html.setAttribute('xml:lang', lang);\n"
	"}\n"
	"getLanguage();\n"
;
