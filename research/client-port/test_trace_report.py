import tempfile,unittest
from pathlib import Path
from port_client import summarize_trace
class TraceReportTests(unittest.TestCase):
    def test_active_trace_partial_row_and_decisions(self):
        with tempfile.TemporaryDirectory() as temp:
            p=Path(temp)/'trace.tsv';p.write_text('sequence\ttick_ms\tsocket\tdirection\tstage\topcode\textended\tbytes\n1\t1\t123\tC2S\tblocked_unsupported\tD0\t25\t11\n2\t2\t123\tS2C\tconverted_C4_clan\t53\t-1\t124\n3\t3\t123\tS2C\tconverted_C4_clan\t53\t-1\t156\n4\t4\t123\tS2C')
            result=summarize_trace(p);self.assertEqual(len(result),2);self.assertEqual(result[1]['count'],2);self.assertEqual(result[1]['lengths'],[124,156]);self.assertEqual(result[0]['stage'],'blocked_unsupported')
