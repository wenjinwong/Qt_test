import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDebug"
    Depends { name: "Qt"; submodules: ["core-private","network","packetprotocol-private"]}

    architectures: ["x86_64"]
    targetPlatform: "linux"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5Network.so"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5QmlDebug"
    libNameForLinkerRelease: "Qt5QmlDebug"
    libFilePathDebug: undefined
    libFilePathRelease: "/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5QmlDebug.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","incremental","release","linux","unix","posix","gcc","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","enable_new_dtags","f16c","force_debug_info","largefile","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","warning_clean","python_available","static","internal_module","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","bsymbolic_functions","separate_debug_info","qt_install_headers","need_fwd_pri","qt_install_module","create_cmake","compiler_supports_fpmath","create_libtool","have_target","staticlib","debug_info","thread","moc","resources"]
    cpp.defines: ["QT_QMLDEBUG_LIB"]
    cpp.includePaths: ["/home/a/Qt5.13.1/5.13.1/gcc_64/include","/home/a/Qt5.13.1/5.13.1/gcc_64/include/QtQmlDebug","/home/a/Qt5.13.1/5.13.1/gcc_64/include/QtQmlDebug/5.13.1","/home/a/Qt5.13.1/5.13.1/gcc_64/include/QtQmlDebug/5.13.1/QtQmlDebug"]
    cpp.libraryPaths: ["/home/qt/openssl-1.1.1b/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["qmldebug-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}